/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:31:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 14:00:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_map *map)
{
	mlx_clear_window(map->mlx, map->window);
	plotpoints(map, map->map_x, map->map_y);
}

void	map_init(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, DEF_W, DEF_H, "FDF");
	draw_map(map);
	mlx_key_hook(map->window, keyhook, map);
	mlx_loop(map->mlx);
}
