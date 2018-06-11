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

void	center(t_map *map)
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
			map->points[i][j].x += map->s_w / 2;
			map->points[i][j].z -= off_y;
			map->points[i][j].z += map->s_h / 2;
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
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x += map->move_x;
			map->points[i][j].y += map->move_y;
			map->points[i][j].z += map->move_z;
			j++;
		}
		i++;
	}
	map->move_x = 0;
	map->move_y = 0;
	map->move_z = 0;
	map->map_x = map->points[map->width / 2][map->height / 2].x;
	map->map_y = map->points[map->width / 2][map->height / 2].y;
	map->map_z = map->points[map->width / 2][map->height / 2].z;
}

void	draw_map(t_map *map)
{
	mlx_clear_window(map->mlx, map->window);
	display(*map);
}

void	map_init(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, MAX_W, MAX_H, "FDF - Standard");
	map->s_w = MAX_W;
	map->s_h = MAX_H;
	translate(map);
	rot_x(90.0f, map);
	rot_y(90.0f, map);
	rot_z(0.0f, map);
	center(map);
	draw_map(map);
	mlx_hook(map->window, 2, 60L << 0, keyhook, map);
	mlx_loop(map->mlx);
}
