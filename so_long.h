#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "minilibx/mlx.h"

# define SPRITE_H				64
# define SPRITE_W				64

# define BUFFER_SIZE	1024
# define OPEN_MAX		255

typedef struct s_vector
{
	int x;
	int y;
}	t_vector;

typedef struct  s_img
{
	// char		*spt_path;
	// void		*img_ptr;
	// t_vector	size;

	void		*img_ptr;
	char		*spt_path;
	t_vector	size;
	t_vector	pos;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;

}	t_img;


typedef struct s_map
{
	char 		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_var
{
	// void		*mlx;
	// void		*win;
	// int			has_enemy;
	// t_map		map;
	// t_img		img;

	void		*mlx;
	void		*win;
	t_map		map;
	t_img		img;
	t_img		enemy;
	int			has_enemy;
}	t_var;

int	get_x_y(t_var *var, char **argv);
int	get_map(t_var *var, char **argv);
int	load_map(t_var var, int row, int col);
int	print_map(t_var var);
int	init(t_var *var);
int	check_args(int argc, char **argv);
int	check_walls(t_var var);
int	check_sprites(t_var var);
int	check_ret(t_var var);
int	check_char(t_var var);
int	check_map(t_var var);
int	error(char *msg);
char	*ft_strstr(char *haystack, char *needle);

///
size_t	ft_strlen(const char *s);

///
int	ft_gnl(int fd, char **line);
void	*ft_strcpy_gnl(char *dst, char *src, size_t n);




#endif
