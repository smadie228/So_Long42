/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 21:22:04 by smadie            #+#    #+#             */
/*   Updated: 2021/12/26 21:29:44 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "minilibx/mlx.h"

# define BUFFER_SIZE	1024
# define OPEN_MAX		255
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define LEFT_KEY				123
# define RIGHT_KEY				124
# define UP_KEY					126
# define DOWN_KEY				125
# define A_KEY					0
# define S_KEY					1
# define D_KEY					2
# define W_KEY					13
# define ESC 					53

# define SPRITE_H				64
# define SPRITE_W				64

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
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
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;
	int			count_enemy;
}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
	t_img		enemy;
	int			has_enemy;
}	t_var;

int		get_x_y(t_var *var, char **argv);
int		init(t_var *var);
int		get_map(t_var *var, char **argv);
int		check_args(int argc, char **argv);
int		check_enemy(t_var *var);
int		print_map(t_var var);
int		key_press(int key, t_var *vars);
int		mlx_close(t_var *var);
int		get_map_x(t_var var);
int		get_map_y(t_var var);
int		check_map(t_var var);
int		error(char *msg);
int		get_init_position(t_var *var);
int		count_collec(t_var *var);
int		check_collect(t_var *var);
int		movements(int key, t_var *var);
int		free_map(t_var *var);
int		free_exit(t_var *var, char *msg);
int		print_steps(t_var *var);
int		step_into_enemy(int key, t_var *var);
int		get_enemy_position(t_var *var);
int		enemy_patrol(t_var *var);
int		enemy_animation(t_var *var);
int		ft_gnl(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_itoa(int n);
size_t	ft_count_digit(long long int n);
void	*ft_strcpy_gnl(char *dst, char *src, size_t n);

#endif
