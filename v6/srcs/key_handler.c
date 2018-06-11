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

void		displacement(int keycode, t_map *map)
{
	if (keycode == ARROW_UP)
		map->move_z -= 1.45f * map->speed;
	if (keycode == ARROW_DOWN)
		map->move_z += 1.45f * map->speed;
	if (keycode == ARROW_LEFT)
		map->move_x -= 1.45f * map->speed;
	if (keycode == ARROW_RIGHT)
		map->move_x += 1.45f * map->speed;
	translate(map);
}

void	inc_height(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->points[i][j].col == C_RED)
				map->points[i][j].y += 10.0f;
			j++;
		}
		i++;
	}
}

void			do_rotate(t_map *map)
{
	rot_x(map->rot_x, map);
	rot_y(map->rot_y, map);
	rot_z(map->rot_z, map);
}

void			rotate(int keycode, t_map *map)
{
	if (keycode == 86)
		map->rot_x += DEF_ANGLE;
	else if (keycode == 88)
		map->rot_x -= DEF_ANGLE;
	else if (keycode == 91)
		map->rot_y += DEF_ANGLE;
	else if (keycode == 84)
		map->rot_y -= DEF_ANGLE;
	else if (keycode == 92)
		map->rot_z += DEF_ANGLE;
	else if (keycode == 89)
		map->rot_z -= DEF_ANGLE;
	do_rotate(map);
}

int				keyhook(int keycode, t_map *map)
{
//	ft_putendl_i("Keypress === ", keycode);
	if (keycode == ESC)
		escape();
	if (keycode == 15)
	{
		map->points = map->og_points;
	}
	rotate(keycode, map);
	window_new(keycode, map);
	draw_map(map);
	return (0);
}
