/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:32:57 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 20:12:24 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_update_counter(int x, int y, t_program *program)
{
	if (program->map->tab[x][y] == 'C')
	{
		program->map->tab[x][y] = '2';
		program->map->counter_cltb--;
	}
	if (program->map->counter_cltb == 0)
		program->map->has_exit = 0;
}

void	ft_game_won(t_program *program)
{
	ft_printf("Movement counter is -> %d\n", program->map->movement_counter++);
	mlx_clear_window(program->mlx, program->win);
	mlx_destroy_image(program->mlx, program->sprite.reference_walls);
	mlx_destroy_image(program->mlx, program->sprite.reference_bgd);
	mlx_destroy_image(program->mlx, program->sprite.reference_cltbs);
	mlx_destroy_image(program->mlx, program->sprite.reference_exit);
	mlx_destroy_image(program->mlx, program->sprite.reference_player);
	free_table(program->map->tab);
	exit(0);
}

int	ft_exit(int key, int x, int y, t_program *program)
{
	if (key == 124 && program->map->tab[x][y + 1] == 'E'
		&& program->map->has_exit == 0)
	{
		program->sprite_position.x += 64;
		ft_game_won(program);
	}
	else if (key == 123 && program->map->tab[x][y - 1] == 'E'
		&& program->map->has_exit == 0)
	{
		program->sprite_position.x -= 64;
		ft_game_won(program);
	}
	else if (key == 125 && program->map->tab[x + 1][y] == 'E'
		&& program->map->has_exit == 0)
	{
		program->sprite_position.y += 64;
		ft_game_won(program);
	}
	else if (key == 126 && program->map->tab[x - 1][y] == 'E'
		&& program->map->has_exit == 0)
	{
		program->sprite_position.y -= 64;
		ft_game_won(program);
	}
	return (0);
}

void	ft_move(t_program *program, int key, size_t x, size_t y)
{
	if (key == 124 && program->map->tab[x][y + 1] != '1' && !ft_exit(key, x, y,
			program) && program->map->tab[x][y + 1] != 'E')
		ft_right(x, y, program);
	else if (key == 123 && program->map->tab[x][y - 1] != '1' && !ft_exit(key,
			x, y, program) && program->map->tab[x][y - 1] != 'E')
		ft_left(x, y, program);
	else if (key == 125 && program->map->tab[x + 1][y] != '1' && !ft_exit(key,
			x, y, program) && program->map->tab[x + 1][y] != 'E')
		ft_down(x, y, program);
	else if (key == 126 && program->map->tab[x - 1][y] != '1' && !ft_exit(key,
			x, y, program) && program->map->tab[x - 1][y] != 'E')
		ft_up(x, y, program);
	else if (key == 53)
		ft_close(program);
}

int	ft_input(int key, void *param)
{
	t_program	*program;
	size_t		x;
	size_t		y;

	program = (t_program *)param;
	mlx_put_image_to_window(program->mlx, program->win,
		program->sprite.reference_bgd, program->sprite_position.x,
		program->sprite_position.y);
	y = program->sprite_position.x / 64;
	x = program->sprite_position.y / 64;
	ft_move(program, key, x, y);
	mlx_put_image_to_window(program->mlx, program->win,
		program->sprite.reference_player, program->sprite_position.x,
		program->sprite_position.y);
	return (0);
}
