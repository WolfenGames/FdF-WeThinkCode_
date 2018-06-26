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

float	ft_distance(t_points p1, t_points p2)
{
	double	d;
	
	d = sqrt((pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2) +
			pow((p1.z - p2.z), 2)));
	return (d);
}

t_points		new_point(int x, int y, int z, t_map *map)
{
	t_points	new_point;

	new_point.x = x;
	new_point.y = -z;
	new_point.z = y;
	if (y > 0)
	{
		new_point.move = TRUE;
		new_point.col = C_RED;
		map->y_height = y;
	}
	else if (y < 0)
	{
		new_point.move = TRUE;
		new_point.col = C_GREEN;
		map->y_height = y;
	}
	else
	{
		new_point.move = FALSE;
		new_point.col = C_BLUE;
	}
	return (new_point);
}
