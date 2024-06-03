#include "../so_long.h"


void ft_update_counter(int x, int y, t_program *program)
{
		if(program->map->tab[x][y] == 'C')
		{
			program->map->tab[x][y] = '2';
			program->map->counter_cltb--;
		}
		if(program->map->counter_cltb == 0)
			 program->map->has_exit = 0;
}

void ft_game_won(t_program *program)
{
		printf("Movement counter is -> %d\n", program->map->movement_counter++);
		// mlx_destroy_image(program->mlx, program->sprite.reference);
		// mlx_destroy_image(program->mlx, program->sprite.reference_bgd);
		mlx_clear_window(program->mlx, program->window.reference);
		free_table(program->map->tab);
		exit(1);
}

int	ft_exit(int key, int x, int y, t_program *program)
{

	if (key == 124 && program->map->tab[x][y + 1] == 'E' && program->map->has_exit == 0)
		{
			program->sprite_position.x += program->sprite.size.x;
			ft_game_won(program);
		}
	else if (key == 123 && program->map->tab[x][y - 1] == 'E' && program->map->has_exit == 0)
		{
			program->sprite_position.x -= program->sprite.size.x;
			ft_game_won(program);
		}
	else if (key == 125 && program->map->tab[x + 1][y] == 'E' && program->map->has_exit == 0)
		{
			program->sprite_position.y += program->sprite.size.y;
			ft_game_won(program);
		}	
	else if (key == 126 && program->map->tab[x - 1][y] == 'E' && program->map->has_exit == 0)
		{
			program->sprite_position.y -= program->sprite.size.y;
			ft_game_won(program);
		}
	return (0);
}
void ft_right(size_t x, size_t y, t_program *program)
{
	program->sprite_position.x += program->sprite.size.x;
	ft_update_counter(x, y, program);
	mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
	printf("Movement counter is -> %d\n", program->map->movement_counter++);
}

void ft_left(size_t x, size_t y, t_program *program)
{
			program->sprite_position.x -= program->sprite.size.x;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		printf("Movement counter is -> %d\n", program->map->movement_counter++);
}
void ft_down(size_t x, size_t y, t_program *program)
{
			program->sprite_position.y += program->sprite.size.y;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		printf("Movement counter is -> %d\n", program->map->movement_counter++);
}
void ft_up(size_t x, size_t y, t_program *program)
{
			program->sprite_position.y -= program->sprite.size.y;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		printf("Movement counter is -> %d\n", program->map->movement_counter++);
}
int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;
	size_t x;
    size_t y;

	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
	
	y = program->sprite_position.x / 64;
	x = program->sprite_position.y / 64;
	if (key == 124 && program->map->tab[x][y + 1] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x][y + 1] != 'E') //go to right
			ft_right(x, y, program);
	else if (key == 123 && program->map->tab[x][y - 1] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x][y - 1] != 'E') //go to left
			ft_left(x, y, program);
	else if (key == 125 && program->map->tab[x + 1][y] != '1'&& !ft_exit(key, x, y, program) && program->map->tab[x + 1][y] != 'E')//go down
			ft_down(x, y, program);	
	else if (key == 126 && program->map->tab[x - 1][y] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x - 1][y] != 'E')//go up
			ft_up(x, y, program);
	else if (key == 53)
			ft_close(program);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_player, program->sprite_position.x, program->sprite_position.y);
	return (0);
}