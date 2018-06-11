/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:35:12 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 11:58:57 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		get_scale(int keycode, t_map *map)
{
	if (keycode == PG_DOWN && map->scale >= 1)
	{
		map->zoom = -1;
		return (-1);
	}
	if (keycode == PG_UP && map->scale < MAX_SCALE)
	{	
		map->zoom = 1;
		return (1);
	}
	return (0);
}

static int		displacement(int keycode, t_map *map)
{
	if (keycode == ARROW_UP)
	{
		map->move_z -= 1 * map->scale;
		translate(map);
	}
	if (keycode == ARROW_DOWN)
	{
		map->move_z += 1 * map->scale;
		translate(map);
	}
	if (keycode == ARROW_LEFT)
	{
		map->move_x -=1 * map->scale;
		translate(map);
	}
	if (keycode == ARROW_RIGHT)
	{
		map->move_x += 1 * map->scale;
		translate(map);
	}
	return (0); 
}

void	scale_map(t_map *map)
{
	if (map->zoom == -1)
		scale_map_down(map);
	else if (map->zoom == 1)
		scale_map_up(map);
}

int				keyhook(int keycode, t_map *map)
{
//	ft_putendl_i("Keypress === ", keycode);
	if (keycode == 15)
	{
		map->points = map->og_points;
		center(map, map->screen_width, map->screen_height);
	}
	if (keycode == ESC)
		escape();
	window_new(keycode, map);
	displacement(keycode, map);
	map->scale += get_scale(keycode, map);
	if (map->zoom)
		scale_map(map);
	draw_map(map);
	return (0);
}
