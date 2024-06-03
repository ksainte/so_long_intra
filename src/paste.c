/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:12:11 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 13:46:49 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"


void ft_paste_walls(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	// program->sprite = ft_new_sprite(program->mlx, "block.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == '1')
		 {
			mlx_put_image_to_window(program->mlx, program->win,
			program->sprite.reference_walls, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
	// mlx_destroy_image(program->mlx, program->sprite.reference);
}

void ft_paste_cltbs(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	// program->sprite = ft_new_sprite(program->mlx, "enemy_01.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == 'C')
		 {
			mlx_put_image_to_window(program->mlx, program->win,
			program->sprite.reference_cltbs, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
	// mlx_destroy_image(program->mlx, program->sprite.reference);
}
void ft_paste_exit(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	// program->sprite = ft_new_sprite(program->mlx, "door_01.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == 'E')
		 {
			mlx_put_image_to_window(program->mlx, program->win,
			program->sprite.reference_exit, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;
	 program->sprite_position.x = 0;
	 x++;
    }
	// mlx_destroy_image(program->mlx, program->sprite.reference);
}
void ft_paste_bg(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	// void *tmp;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	// program->sprite = ft_new_sprite(program->mlx, "Background.xpm");
	// tmp = program->sprite.reference;
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
		mlx_put_image_to_window(program->mlx, program->win,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		program->sprite_position.x += 64;
		program->sprite_position.y = program->sprite_position.y;
		 y++;
     }
	 program->sprite_position.y += 64;
	 program->sprite_position.x = 0;
	 x++;
    }
	// mlx_destroy_image(program->mlx, program->sprite.reference);
}