/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:31:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 12:01:28 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	center(t_map *map, int x, int y)
{
	int		i;
	int		j;
	int		off_x;
	int		off_y;

	i = 0;
	off_x = map->points[map->height / 2][map->width / 2].x;
	off_y = map->points[map->height / 2][map->width / 2].z;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x -= off_x;
			map->points[i][j].x += x / 2;
			map->points[i][j].z -= off_y;
			map->points[i][j].z += y / 2;
			j++;
		}
		i++;
	}
}

void	translate(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			map->points[i][j].x += map->map_x;
			map->points[i][j].y += map->map_y;
			map->points[i][j].z += map->map_z;
		}
	}
}

void	draw_map(t_map *map)
{
	mlx_clear_window(map->mlx, map->window);
	if (map->has_reset_on_launch < 1)
	{
		map->map_x = 0;
		map->map_y = 0;
		map->map_z = 0;
		map->has_reset_on_launch = 2;
	}
	display(*map);
}

void	map_init(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, DEF_W, DEF_H, "FDF - Standard");
	center(map, DEF_W, DEF_H);
	draw_map(map);
	mlx_key_hook(map->window, keyhook, map);
	mlx_loop(map->mlx);
}
