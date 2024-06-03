/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:43:45 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 17:04:53 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void	free_table(char **buffer)
{
	int	i;

	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	free(buffer);
}
void	exit_err(int errnum)
{
	perror(strerror(errnum));
	exit(EXIT_FAILURE);
}
void	ft_print_table(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
int	ft_close(t_program *program)
{
		mlx_clear_window(program->mlx, program->win);
		mlx_destroy_image(program->mlx, program->sprite.reference_player);
		mlx_destroy_image(program->mlx, program->sprite.reference_bgd);
		mlx_destroy_image(program->mlx, program->sprite.reference_exit);
		mlx_destroy_image(program->mlx, program->sprite.reference_cltbs);
		mlx_destroy_image(program->mlx, program->sprite.reference_walls);
		free_table(program->map->tab);
		system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
		exit(1);
}