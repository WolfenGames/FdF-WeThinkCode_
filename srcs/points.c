/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:10:46 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 08:13:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_points		new_point(int x, int y, int z)
{
	t_points	new_point;

	new_point.x = x;
	new_point.y = z;
	new_point.z = y;
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
