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
	if (map->has_reset_on_launch < 1)
	{
		map->map_x = map->points[map->width / 2][map->height / 2].x;
		map->map_y = map->points[map->width / 2][map->height / 2].y;
		map->map_z = map->points[map->width / 2][map->height / 2].z;
		map->move_x = 0;
		map->move_y = 0;
		map->move_z = 0;
		map->zoom = 0;
		map->has_reset_on_launch = 2;
	}
	display(*map);
}

void	scale_map_down(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x -= (map->scale * i + 1);
			map->points[i][j].z -= (map->scale * j + 1);
			j++;
		}
		i++;
	}
	center(map, map->screen_width, map->screen_height);
	map->zoom = 0;
}

void	scale_map_up(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x += (map->scale * i + 1);
			map->points[i][j].z += (map->scale * j + 1);
			j++;
		}
		i++;
	}
	center(map, map->screen_width, map->screen_height);
	map->zoom = 0;
}

void	map_init(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, DEF_W, DEF_H, "FDF - Standard");
	map->screen_width = DEF_W;
	map->screen_height = DEF_H;
	scale_map_up(map);
	center(map, map->screen_width, map->screen_height);
	draw_map(map);
	translate(map);
	mlx_hook(map->window, 2, 1L << 0, keyhook, map);
	mlx_loop(map->mlx);
}
