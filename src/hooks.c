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
// void ft_right(t_program *program)
// {
// 	program->sprite_position.x += program->sprite.size.x;
// 	ft_update_counter(x, y, program);
// 	mlx_put_image_to_window(program->mlx, program->window.reference,
// 	img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
// }
int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;//ou int x, creation de variable
	// t_image img;

	program->sprite.reference_bgd = mlx_xpm_file_to_image(program->mlx, "Background.xpm", &program->sprite.size.x, &program->sprite.size.y);
	// img.reference_bgd = mlx_xpm_file_to_image(program->mlx, "Background.xpm", &img.size.x, &img.size.y);
	// mlx_put_image_to_window(program->mlx, program->window.reference,
	// 	img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
	
	int x;
    int y;

	y = program->sprite_position.x / 64;
	x = program->sprite_position.y / 64;
	if (key == 124 && program->map->tab[x][y + 1] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x][y + 1] != 'E') //go to right
		{
			program->sprite_position.x += program->sprite.size.x;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}
	else if (key == 123 && program->map->tab[x][y - 1] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x][y - 1] != 'E') //go to left
		{
			program->sprite_position.x -= program->sprite.size.x;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}
	else if (key == 125 && program->map->tab[x + 1][y] != '1'&& !ft_exit(key, x, y, program) && program->map->tab[x + 1][y] != 'E')//go down
		{
			program->sprite_position.y += program->sprite.size.y;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}	
	else if (key == 126 && program->map->tab[x - 1][y] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x - 1][y] != 'E')//go up
		{
			program->sprite_position.y -= program->sprite.size.y;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}
	else if (key == 53)
		{
			mlx_clear_window(program->mlx, program->window.reference);
			free_table(program->map->tab);
			exit(1);
		}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	printf("Movement counter is -> %d\n", program->map->movement_counter++);
	return (0);
}