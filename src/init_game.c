/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:27:33 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 17:21:54 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void ft_init_textures_pointers(t_program *program)
{
		program->sprite.reference_bgd = mlx_xpm_file_to_image(program->mlx, "./textures/Background.xpm",  &program->isize[0], &program->isize[1]);
		program->sprite.reference_walls = mlx_xpm_file_to_image(program->mlx, "./textures/block.xpm",  &program->isize[0], &program->isize[1]);
		program->sprite.reference_cltbs = mlx_xpm_file_to_image(program->mlx, "./textures/enemy_01.xpm",  &program->isize[0], &program->isize[1]);
		program->sprite.reference_exit = mlx_xpm_file_to_image(program->mlx, "./textures/door_01.xpm",  &program->isize[0], &program->isize[1]);
		program->sprite.reference_player = mlx_xpm_file_to_image(program->mlx, "./textures/player_01.xpm",  &program->isize[0], &program->isize[1]);
}
void ft_init_window(t_program *program, t_map *map)
{
	program->lenght = map->row_size * 64;
	program->height = map->row * 64;
	if(program->lenght > 2560 || program->height > 1440)
	{	
		ft_printf("Map size is exceeding screen size, aborting the game launch...\n");
		free_table(map->tab);
		ft_error();	
	}
	program->mlx = mlx_init();
	program->win = mlx_new_window(program->mlx, program->lenght, program->height, "Hello so_long!");
	ft_init_textures_pointers(program);
	ft_paste_bg(program, map);
	ft_paste_walls(program, map);
	ft_paste_cltbs(program, map);
	ft_paste_exit(program, map);
}
void ft_init_player(t_program *program, t_map *map)
{
    program->sprite_position.x = map->starting_y * 64;
    program->sprite_position.y = map->starting_x * 64;
	mlx_put_image_to_window(program->mlx, program->win,
        program->sprite.reference_player, program->sprite_position.x, program->sprite_position.y);
	program->map = map;
	map->movement_counter++;
	mlx_hook(program->win, 2, 0,*ft_input, program);
	mlx_hook(program->win, 17, 0, *ft_close, program);
}