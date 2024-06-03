/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:40:24 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 18:45:30 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clean_program(t_map *map, char *path)
{
	free(map->line);
	free(path);
	map->return_value = close(map->fd);
	if (map->return_value == -1)
		exit_err(errno);
	ft_error();
}

int	ft_is_rectangular(t_map *map)
{
	size_t	len_first;
	size_t	i;

	len_first = ft_strlen(map->tab[0]);
	i = 0;
	while (map->tab[i])
	{
		if (len_first != ft_strlen(map->tab[i]))
			return (0);
		i++;
	}
	map->row_size = ft_strlen(map->tab[0]);
	return (1);
}

int	ft_has_walls(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map->tab[x])
	{
		if (map->tab[x][0] != '1' || map->tab[x][map->row_size - 1] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (map->tab[0][y])
	{
		if (map->tab[0][y] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (map->tab[map->row - 1][y])
	{
		if (map->tab[map->row - 1][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	char_check(char c, t_map *map)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'C' && c != 'P')
		return (0);
	if (c == 'E')
	{
		map->counter_exit++;
		if (map->counter_exit > 1)
			return (0);
	}
	if (c == 'C')
		map->counter_cltb++;
	if (c == 'P')
	{
		map->counter_pos++;
		if (map->counter_pos > 1)
			return (0);
	}
	return (1);
}

int	ft_char_is_legit(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map->tab[x])
	{
		y = 0;
		while (map->tab[x][y])
		{
			if (!char_check(map->tab[x][y], map))
				return (0);
			if (map->tab[x][y] == 'P')
			{
				map->starting_x = x;
				map->starting_y = y;
			}
			y++;
		}
		x++;
	}
	if (map->counter_exit == 0 || map->counter_cltb == 0
		|| map->counter_pos == 0)
		return (0);
	return (1);
}
