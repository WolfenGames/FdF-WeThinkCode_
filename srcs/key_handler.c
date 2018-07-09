/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:35:12 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/09 07:18:05 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		get_scale(int keycode, t_map *map)
{
	float 	sv;
	 
	sv = 0.3f;
	if (keycode == PG_DOWN || keycode == PG_UP)
	{
		if (keycode == PG_DOWN && map->scale > 1)
			map->scale -= (map->scale * sv);
		if (keycode == PG_UP && map->scale < MAX_SCALE)
			map->scale += (map->scale * sv);
		mapify(map, &map->points);
		rot_x(map->rot_x, map);
		rot_y(map->rot_y, map);
		rot_z(map->rot_z, map);
	}
	return (0);
}

int			rotate(int keycode, t_map *map)
{
	if (keycode == NUM_2 || keycode == NUM_4 || keycode == NUM_6 ||
		keycode == NUM_8 || keycode == NUM_1 || keycode == NUM_3 ||
		keycode == NUM_7 || keycode == NUM_9)
	{
		if (keycode == NUM_4)
			map->rot_x += 1;
		if (keycode == NUM_6)
			map->rot_x -= 1;
		if (keycode == NUM_8)
			map->rot_y += 1;
		if (keycode == NUM_2)
			map->rot_y -= 1;
		if (keycode == NUM_7 || keycode == NUM_9)
			map->rot_z += 1;
		if (keycode == NUM_1 || keycode == NUM_3)
			map->rot_z -= 1;
		mapify(map, &map->points);
		rot_x(map->rot_x, map);
		rot_y(map->rot_y, map);
		rot_z(map->rot_z, map);
	}
	return (0);
}

void			change_height(int keycode, t_map *map)
{
	int		i;
	int		j;
	int		val;

	i = 0;
	val = 0;
	if (keycode == W)
		val = -1 * MS;
	if (keycode == S)
		val = 1 * MS;
	if (val != 0)
	{
		while (i < map->height)
		{
			j = 0;
			while (j < map->width)
			{
				if (MP[i][j].move == TRUE)
				{
					MP[i][j].z += val;
					map->y_height = MP[i][j].z;
				}
				j++;
			}
			i++;
		}
	}
}

static int		displacement(int keycode, t_map *map)
{
	if (keycode == ARROW_UP)
		map->move_z -= 0.3f * map->scale;
	if (keycode == ARROW_DOWN)
		map->move_z += 0.3f * map->scale;
	if (keycode == ARROW_LEFT)
		map->move_x -= 0.3f * map->scale;
	if (keycode == ARROW_RIGHT)
		map->move_x += 0.3f * map->scale;
	return (0); 
}

int				keyhook(int keycode, t_map *map)
{
	if (keycode == ESC)
		escape();
	window_new(keycode, map);
	displacement(keycode, map);
	rotate(keycode, map);
	get_scale(keycode, map);
	center(map, map->curr_width + map->move_x, map->curr_height + map->move_z);
	draw_map(map);
	//free_points(cpy);
	return (0);
}
