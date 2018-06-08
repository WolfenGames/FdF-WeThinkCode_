/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:10:46 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 11:11:38 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_points		new_point(int x, int y, int z)
{
	t_points	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	if (y > 1)
		new_point.col = C_GREEN;
	else
		new_point.col = C_RED;
	return (new_point);
}

void			translate(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x += map->map_x;
			map->points[i][j].y += map->map_y;
			map->points[i][j].z += map->map_z; 
		}
		i++;
	}
}

void			incHeight(t_map *map, int scalex, int scaley)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x *= scalex;
			map->points[i][j].y *= scaley;
			map->points[i][j].z *= scalex;
			j++;
		}
		i++;
	}
}
