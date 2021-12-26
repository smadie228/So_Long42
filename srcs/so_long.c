/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:38:46 by bvirgini          #+#    #+#             */
/*   Updated: 2021/12/26 06:08:13 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init(t_var *var)
{
	var->map.mtx = malloc((var->map.size.y + 1) * sizeof(char *));
	var->map.mtx[var->map.size.y] = NULL;
	// var->game.count_steps = 0;
	// var->game.count_enemy = 0;
	// var->enemy.pos.x = 0;
	// var->enemy.pos.y = 0;
	// var->has_enemy = 0;
	var->img.spt_path = "./img/sprite.xpm";
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		error("Provide map name and extension as argument\n\
Ex: ./so_long maps/map.ber");
	if (argc > 2)
		error("Too many arguments. Provide only map name and extension\n\
Ex: ./so_long maps/map.ber");
	if (ft_strstr(argv[1], ".ber") == NULL)
		error("Invalid map extension. Use .ber");
	return (0);
}


int	main(int argc, char **argv)
{
	t_var	var;

	check_args(argc, argv);
	get_x_y(&var, argv);
	init(&var);
	get_map(&var, argv);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * SPRITE_W, var.map.size.y
			* SPRITE_H, "So long");
	print_map(var);
	mlx_loop(var.mlx);
}
