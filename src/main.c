/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:19 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 17:10:21 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static	void	check_arg(int ac, char *str)
{
	if (ac < 2 || str == NULL)
	{
		ft_printf("Erreur\nCarte manquante : ./so_long <map>\n");
		exit(1);
	}
	else if (ac > 2)
	{
		ft_printf("Erreur\nTrop d'arguments : ./so_long <map>\n");
		exit(1);
	}
	while (*str != '.' && *str != '\0')
		str++;
	if (ft_strncmp(".ber", str, 4) != 0 || ft_strlen(str) != 4)
	{
		ft_printf("Erreur\nExtension du fichier carte non valide : <map>.ber");
		exit(1);
	}
	return ;
}
void ft_row_number(t_map *map, char *path)
{	
    map->fd = open(path , O_RDONLY);
	if (map->fd == -1)
		exit_err(errno);
	map->line = (char *)malloc(sizeof(char*));
	if(!map->line)
		return ;
    while (map->line != NULL)
    {
		if (map->line)
			free(map->line);
        map->line = get_next_line(map->fd);
		if (map->line == 0 || *map->line == '\n')
			break;
        map->row++;
    }
	if(map->line != 0)
		ft_check_left_over(map, path);
}
void ft_fill_tab(t_map *map, char *path)
{
    char *tmp;
	char *tmp1;
    size_t   i;

    i = 0;
	map->tab = calloc(map->row + 1, sizeof(char*));
	if(!map->tab)
		return ;
	map->fd = open(path, O_RDONLY);
	while (i < map->row)
	{
		map->tab[i] = get_next_line(map->fd);
		tmp = map->tab[i];
		map->tab[i] = ft_strtrim(map->tab[i], "\n");
		tmp1 = map->tab[i];
		map->tab[i] = ft_strtrim_end(map->tab[i], " ");
		free(tmp);
		free(tmp1);
		i++;
	}
	map->tab[i] = NULL;
	map->return_value = close(map->fd);
	if(map->return_value == -1)
		exit_err(errno);
	free(path);
}
void ft_valid_map(t_map *map)
{
	if (!(ft_is_rectangular(map) && ft_has_walls(map) && ft_char_is_legit(map)))
	{
		printf("\nMap has invalid format\n");
		ft_print_table(map->tab);
		free_table(map->tab);
		ft_error();
	}
	map->has_all_cltb = map->counter_cltb;
	ft_init_tmp(map);
	ft_has_valid_path(map, map->starting_x, map->starting_y);
	if(!(map->has_exit == 1 && map->has_all_cltb == 0))
	{
		printf("\nMap has valid format but invalid path\n");
		ft_print_table(map->tab);
		free_table(map->tab);
		free_table(map->tmp);
		ft_error();
	}
	else
	{
		printf("\nMap has valid format and valid path, launching the game...\n");
		ft_print_table(map->tab);
		free_table(map->tmp);
	}
}
int	main(int argc, char **argv)
{
    static t_map   map;
	t_program 	program;
	char *path;
	
	check_arg(argc, argv[1]);
	path = ft_strjoin("./maps/", argv[1]);
	if (!path)
		ft_error();
    ft_row_number(&map, path);
    ft_fill_tab(&map, path);
	ft_valid_map(&map);
	ft_init_window(&program, &map);
	ft_init_player(&program, &map);
	mlx_loop(program.mlx);
	// free_table(map.tab);
	system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
}