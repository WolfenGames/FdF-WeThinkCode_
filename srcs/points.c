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
	if (y == 0)
		new_point.col = 0;
	else if (y > x)
		new_point.col = 1;
	else
		new_point.col = 2;
	return (new_point);
}
