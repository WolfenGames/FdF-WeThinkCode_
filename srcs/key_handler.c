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

void	keyhook(int keycode, t_map *map)
{
	t_map	mapcpy;

	mapcpy = *map;
	if (keycode == ESC)
		escape();
	if (keycode == ARROW_RIGHT)
		map->move_x = 10.0f;
	if (keycode == ARROW_LEFT)
		map->move_x = -(10.0f);
	if (keycode == ARROW_UP)
		map->move_z = -(10.0f);
	if (keycode == ARROW_DOWN)
		map->move_z = 10.0f;
	if (keycode == PG_UP)
		map->move_y = 10.0f;
	if (keycode == PG_DOWN)
		map->move_y = -(10.0f);
	if (keycode == NUM_PLUS)
	{
		map->scale_x = 1.5f;
		map->scale_z = 1.5f;
	}
	if (keycode == NUM_MINUS)
	{
		map->scale_x = -2;
		map->scale_z = -2;
	}
	map->og_points = simulacron(map);
	scale_map(map);
	move_map(map);
	draw_map(map);
}