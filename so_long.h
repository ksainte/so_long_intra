/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/02 21:48:04 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
#include "./get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

// //I highly recommend using stack-allocated memory as much as possible, as it will make your life so much easier when you need to exit the program.
// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
// }	t_data;

# define LENGTH 400
# define HEIGHT 100

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;


/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	void		*reference_bgd;
	void		*reference_enmy;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct t_struct
{
	char	**tab;
	char	**tmp;
	char 	*line;
	size_t 	row;
	int		fd;
	int		return_value;
	size_t	row_size;
	int 	counter_cltb;
	int 	counter_exit;
	int 	counter_pos;
	int		starting_x;
	int		starting_y;
	int		has_exit;
	int		has_all_cltb;
	int		movement_counter;
}	t_map;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_map		*map;
	t_vector	sprite_position;
	size_t		lenght;
	size_t		height;
}				t_program;


t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
char		*ft_strtrim_end(char const *s1, char const *set);
int 		ft_is_rectangular(t_map *map);
int 		ft_has_walls(t_map *map);
int 		char_check(char c, t_map *map);
int 		ft_char_is_legit(t_map *map);
void		free_table(char **buffer);
void		ft_error(void);
void 		ft_paste_walls(t_program *program, t_map *map);
void 		ft_paste_cltbs(t_program *program, t_map *map);
void 		ft_paste_exit(t_program *program, t_map *map);
void 		ft_paste_start(t_program *program, t_map *map);
void 		ft_paste_bg(t_program *program, t_map *map);
void 		ft_row_number(t_map *map, char *path);
void 		ft_fill_tab(t_map *map, char *path);
void 		ft_init_tmp(t_map *map);
void 		ft_valid_map(t_map *map);
void		exit_err(int errnum);
void		ft_print_table(char **tab);
int			ft_close(t_program *program);
int			ft_input(int key, void *program);

#endif