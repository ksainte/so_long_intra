#include"../so_long.h"

void ft_check_left_over(t_map *map, char *path)
{
	while(map->line != 0)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && map->line[0] != '\n')
		{
			free(map->line);
			free(path);
			map->return_value = close(map->fd);
    		if(map->return_value == -1)
				exit_err(errno);
			ft_error();
		}
	}
}
void ft_row_number(t_map *map, char *path)
{	
    map->fd = open(path , O_RDONLY);
	if (map->fd == -1)
		exit_err(errno);
	map->line = (char *)malloc(sizeof(char*));
	if(!map->line)
		return ;
    while (map->line != NULL)
    {
		if (map->line)
			free(map->line);
        map->line = get_next_line(map->fd);
		if (map->line == 0 || *map->line == '\n')
			break;
        map->row++;
    }
	if(map->line != 0)
		ft_check_left_over(map, path);
}
void	exit_err(int errnum)
{
	perror(strerror(errnum));
	exit(EXIT_FAILURE);
}

void ft_fill_tab(t_map *map, char *path)
{
    char *tmp;
	char *tmp1;
    size_t   i;

    i = 0;
	map->tab = calloc(map->row + 1, sizeof(char*));
	if(!map->tab)
		return ;
	map->fd = open(path, O_RDONLY);
	while (i < map->row)
	{
		map->tab[i] = get_next_line(map->fd);
		tmp = map->tab[i];
		map->tab[i] = ft_strtrim(map->tab[i], "\n");
		tmp1 = map->tab[i];
		map->tab[i] = ft_strtrim_end(map->tab[i], " ");
		free(tmp);
		free(tmp1);
		i++;
	}
	map->tab[i] = NULL;
	map->return_value = close(map->fd);
	if(map->return_value == -1)
		exit_err(errno);
	free(path);
}
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_end(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (end && ft_check_char(s1[end - 1], set))
		end--;
	str = (char *)s1;
	str = (char *)malloc(sizeof(*s1) * (end + 1));
	if (!str)
		return (NULL);
	i = 0;
    start = 0; 
	while (i < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
int ft_is_rectangular(t_map *map)
{	
	size_t len_first;
	size_t i;

	len_first = ft_strlen(map->tab[0]);
	i = 0;
	while(map->tab[i])
	{
		if(len_first != ft_strlen(map->tab[i]))
			return(0);
		i++;
	}
	map->row_size = ft_strlen(map->tab[0]);
	return(1);
}

int ft_has_walls(t_map *map)
{
	size_t x;
	size_t y;
	
	x = 0;
	while(map->tab[x])
	{
		if(map->tab[x][0] != '1' || map->tab[x][map->row_size - 1] != '1')
			return(0);
		x++;
	}
	y = 0;
	while(map->tab[0][y])
	{
		if(map->tab[0][y] != '1')
			return(0);
		y++;
	}
	y = 0;
	while(map->tab[map->row - 1][y])
	{
		if(map->tab[map->row - 1][y] != '1')
			return(0);
		y++;
	}
	return(1);
}
int char_check(char c, t_map *map)
{
			if (c != '0' && c != '1' && c != 'E' && c != 'C' && c != 'P')
				return(0);
			if (c == 'E')
			{
				map->counter_exit++;
				if(map->counter_exit > 1)
					return(0);
			}
			if (c == 'C')
				map->counter_cltb++;
			if (c == 'P')
			{	
				map->counter_pos++;
				if(map->counter_pos > 1)
					return(0);
			}
		return(1);
}
int ft_char_is_legit(t_map *map)
{
	size_t x;
	size_t y;

	x = 0;
	while(map->tab[x])
	{
		y = 0;
		while(map->tab[x][y])
		{
			if(!char_check(map->tab[x][y], map))
					return(0);
			if(map->tab[x][y] == 'P')
			{
				map->starting_x = x;
				map->starting_y = y;
			}
			y++;
		}
	x++;
	}
	if(map->counter_exit == 0 || map->counter_cltb == 0 || map->counter_pos == 0)
			return(0);
	return(1);
}

int ft_n_in_line(char *str)
{
	
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return(1);
		i++;
	}
	return(0);
	
}
void	free_table(char **buffer)
{
	int	i;

	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	free(buffer);
}