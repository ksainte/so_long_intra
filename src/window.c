#include "../so_long.h"

/* Returning a void pointer that is a reference to the opened window with a given size and name */
t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}


