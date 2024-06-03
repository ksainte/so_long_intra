#include "../so_long.h"

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	return (img);
}
