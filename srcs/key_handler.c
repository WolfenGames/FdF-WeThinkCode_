/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:35:12 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/18 09:15:54 by jwolf            ###   ########.fr       */
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
	t_points	**cpy;

	cpy = simulacron(map);
	if (keycode == ESC)
		escape(map);
	window_new(keycode, map);
	displacement(keycode, map);
//	change_height(keycode, map);
	get_scale(keycode, map);
//	do_rot(map);
	center(map, map->curr_width + map->move_x, map->curr_height + map->move_z);
	draw_map(map);
	free(cpy);
	return (0);
}
