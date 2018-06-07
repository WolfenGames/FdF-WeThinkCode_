/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:35:12 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 15:34:21 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_displacement_x(int keycode)
{
	if (keycode == ARROW_LEFT)
		return (-1);
	if (keycode == ARROW_RIGHT)
		return (1);
	return (0); 
}

static int	get_displacement_y(int keycode)
{
	if (keycode == ARROW_UP)
		return (-1);
	if (keycode == ARROW_DOWN)
		return (1);
	return (0);
}

static	int	get_scale(int keycode, t_map *map)
{
	if (keycode == PG_DOWN && map->scale >= 2)
		return (-1);
	if (keycode == PG_UP && map->scale < MAX_SCALE)
		return (1);
	return (0);
}

int		keyhook(int keycode, t_map *map)
{
	if (keycode == ESC)
		exit(0);
	map->map_x += get_displacement_x(keycode) * map->scale;
	map->map_y += get_displacement_y(keycode) * map->scale;
	map->scale += get_scale(keycode, map);
	draw_map(map);
	return (0);
}
