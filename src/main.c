/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:19 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/02 21:02:35 by ksainte          ###   ########.fr       */
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


static	void ft_has_valid_path(t_map *map, int x, int y)
{
	
	if(map->tmp[x][y] == 'E')
		map->has_exit = 1;
	if(map->tmp[x][y] == 'C')
		map->has_all_cltb--;
	//valid paths on the way, if you can reach C and E through it youre good to go
	if(map->tmp[x][y] == '0' || map->tmp[x][y] == 'C' || map->tmp[x][y] == 'E' || map->tmp[x][y] == 'P')
	{
		map->tmp[x][y] = '2';
		ft_has_valid_path(map, x - 1, y);
		ft_has_valid_path(map, x + 1, y);
		ft_has_valid_path(map, x, y - 1);
		ft_has_valid_path(map, x, y + 1);  
	}
}

void ft_init_tmp(t_map *map)
{
	size_t x;

	x = 0;
	map->tmp = ft_calloc(map->row + 1, sizeof(char*));
	if(!map->tmp)
		return ;
	while(map->tab[x])
	{
			map->tmp[x] = ft_strdup(map->tab[x]);
			x++;
	}
	map->tmp[x]= NULL;
}
void	ft_print_table(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
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
		printf("Map has valid format and valid path, launching the game...\n");
		ft_print_table(map->tab);
		free_table(map->tmp);
	}
}

void ft_init_window(t_program *program, t_map *map)
{
	program->lenght = map->row_size * 64;
	program->height = map->row * 64;
	if(program->lenght > 2560 || program->height > 1440)
	{	
		printf("Map size is exceeding screen size, aborting the game launch...\n");
		free_table(map->tab);
		ft_error();	
	}
	program->mlx = mlx_init();
	program->window = ft_new_window(program->mlx, program->lenght, program->height, "Hello world!");
	ft_paste_bg(program, map);
	ft_paste_walls(program, map);
	ft_paste_cltbs(program, map);
	ft_paste_exit(program, map);
}
static int	ft_close(t_program *program)
{
		mlx_clear_window(program->mlx, program->window.reference);
		free_table(program->map->tab);
		exit(1);
}
void ft_init_player(t_program *program, t_map *map)
{
	program->sprite = ft_new_sprite(program->mlx, "player_01.xpm");
    program->sprite_position.x = map->starting_y * 64;
    program->sprite_position.y = map->starting_x * 64;
	program->map = map;
    mlx_put_image_to_window(program->mlx, program->window.reference,
        program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	printf("Movement counter is -> %d\n", map->movement_counter++);
	mlx_hook(program->window.reference, 2, 0,*ft_input, program);
	mlx_hook(program->window.reference, 17, 0, *ft_close, program);
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
	free_table(map.tab);
	system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
}