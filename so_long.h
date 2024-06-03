/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/06/03 18:47:41 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_image
{
	void		*reference_player;
	void		*reference_bgd;
	void		*reference_exit;
	void		*reference_cltbs;
	void		*reference_walls;
}				t_image;

typedef struct t_struct
{
	char		**tab;
	char		**tmp;
	char		*line;
	size_t		row;
	int			fd;
	int			return_value;
	size_t		row_size;
	int			counter_cltb;
	int			counter_exit;
	int			counter_pos;
	int			starting_x;
	int			starting_y;
	int			has_exit;
	int			has_all_cltb;
	int			movement_counter;
}				t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	int			isize[2];
	t_image		sprite;
	t_map		*map;
	t_vector	sprite_position;
	size_t		lenght;
	size_t		height;
}				t_program;

char			*ft_strtrim_end(char const *s1, char const *set);
int				ft_is_rectangular(t_map *map);
int				ft_has_walls(t_map *map);
int				char_check(char c, t_map *map);
int				ft_char_is_legit(t_map *map);
void			free_table(char **buffer);
void			ft_error(void);
void			ft_paste_walls(t_program *program, t_map *map);
void			ft_paste_cltbs(t_program *program, t_map *map);
void			ft_paste_exit(t_program *program, t_map *map);
void			ft_paste_bg(t_program *program, t_map *map);
void			ft_row_number(t_map *map, char *path);
void			ft_fill_tab(t_map *map, char *path);
void			ft_init_tmp(t_map *map);
void			ft_valid_map(t_map *map);
void			exit_err(int errnum);
void			ft_print_table(char **tab);
int				ft_close(t_program *program);
int				ft_input(int key, void *program);
void			ft_init_player(t_program *program, t_map *map);
void			ft_init_window(t_program *program, t_map *map);
void			ft_up(size_t x, size_t y, t_program *program);
void			ft_down(size_t x, size_t y, t_program *program);
void			ft_left(size_t x, size_t y, t_program *program);
void			ft_right(size_t x, size_t y, t_program *program);
void			ft_update_counter(int x, int y, t_program *program);
void			ft_check_left_over(t_map *map, char *path);
void			ft_has_valid_path(t_map *map, int x, int y);
void			ft_clean_program(t_map *map, char *path);

#endif