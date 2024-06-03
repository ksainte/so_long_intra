/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:41:53 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 19:10:00 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_left_over(t_map *map, char *path)
{
	while (map->line != 0)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && map->line[0] != '\n')
			ft_clean_program(map, path);
	}
}

static int	ft_check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_end(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (end && ft_check_char(s1[end - 1], set))
		end--;
	str = (char *)s1;
	str = (char *)malloc(sizeof(*s1) * (end + 1));
	if (!str)
		return (NULL);
	i = 0;
	start = 0;
	while (i < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

void	ft_init_tmp(t_map *map)
{
	size_t	x;

	x = 0;
	map->tmp = ft_calloc(map->row + 1, sizeof(char *));
	if (!map->tmp)
		return ;
	while (map->tab[x])
	{
		map->tmp[x] = ft_strdup(map->tab[x]);
		x++;
	}
	map->tmp[x] = NULL;
}

void	ft_has_valid_path(t_map *map, int x, int y)
{
	if (map->tmp[x][y] == 'E')
		map->has_exit = 1;
	if (map->tmp[x][y] == 'C')
		map->has_all_cltb--;
	if (map->tmp[x][y] == '0' || map->tmp[x][y] == 'C' || map->tmp[x][y] == 'P')
	{
		map->tmp[x][y] = '2';
		ft_has_valid_path(map, x - 1, y);
		ft_has_valid_path(map, x + 1, y);
		ft_has_valid_path(map, x, y - 1);
		ft_has_valid_path(map, x, y + 1);
	}
}
