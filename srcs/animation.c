/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:29:21 by smadie            #+#    #+#             */
/*   Updated: 2021/12/26 21:20:13 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemy_animation(t_var *var)
{
	if (var->enemy.pos.x % 2 == 0)
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm",
				&var->img.size.x, &var->img.size.y);
	else
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm",
				&var->img.size.x, &var->img.size.y);
	return (0);
}
