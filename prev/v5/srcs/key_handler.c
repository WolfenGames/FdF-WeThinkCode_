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
	if (keycode == PG_DOWN && map->scale >= 2)
		return (-1);
	if (keycode == PG_UP && map->scale < MAX_SCALE)
		return (1);
	return (0);
}

static int		displacement(int keycode, t_map *map)
{
	if (keycode == ARROW_UP)
	{
		map->move_z -= 1 * map->scale;
	}
	if (keycode == ARROW_DOWN)
	{
		map->move_z += 1 * map->scale;
	}
	if (keycode == ARROW_LEFT)
	{
		map->move_x -=1 * map->scale;
	}
	if (keycode == ARROW_RIGHT)
	{
		map->move_x += 1 * map->scale;
	}
	translate(map);
	return (0); 
}

int				keyhook(int keycode, t_map *map)
{
	if (keycode == ESC)
		escape();
	window_new(keycode, map);
	displacement(keycode, map);
	map->scale += get_scale(keycode, map);
	draw_map(map);
	return (0);
}
