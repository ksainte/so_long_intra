/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:32:33 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 16:32:51 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_right(size_t x, size_t y, t_program *program)
{
	program->sprite_position.x += 64;
	ft_update_counter(x, y, program);
	mlx_put_image_to_window(program->mlx, program->win,
			program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
	ft_printf("Movement counter is -> %d\n", program->map->movement_counter++);
}

void ft_left(size_t x, size_t y, t_program *program)
{
			program->sprite_position.x -= 64;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->win,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		ft_printf("Movement counter is -> %d\n", program->map->movement_counter++);
}
void ft_down(size_t x, size_t y, t_program *program)
{
			program->sprite_position.y += 64;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->win,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		ft_printf("Movement counter is -> %d\n", program->map->movement_counter++);
}
void ft_up(size_t x, size_t y, t_program *program)
{
			program->sprite_position.y -= 64;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->win,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		ft_printf("Movement counter is -> %d\n", program->map->movement_counter++);
}