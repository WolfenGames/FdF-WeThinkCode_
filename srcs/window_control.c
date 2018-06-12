/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcontrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:20:37 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 13:20:40 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	window_new(int keycode, t_map *map)
{
	if (keycode == NUM_PLUS)
	{
		mlx_destroy_window(map->mlx, map->window);
		map->window = mlx_new_window(map->mlx, MAX_W, MAX_H, "FdF - MAX");
		map->s_w = MAX_W;
		map->s_h = MAX_H;
		center(map);
		mlx_hook(map->window, 2, 0, keyhook, map);
	}
	else if (keycode == NUM_MINUS)
	{
		mlx_destroy_window(map->mlx, map->window);
		map->window = mlx_new_window(map->mlx, DEF_W, DEF_H, "FdF - MIN");
		map->s_w = DEF_W;
		map->s_h= DEF_H;
		center(map);
		mlx_hook(map->window, 2, 0, keyhook, map);
	}
}

void	escape(void)
{
	ft_putendl("Thank you for playing Jumanji Beta version... early beta");
	exit(0);
}
