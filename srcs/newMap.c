/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:07:44 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 17:25:40 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*newMap(t_map *map)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = 0;
	point->y = 0;
	map->pos.x = 0;
	map->pos.y = 0;
	map->points = point;
	free(point);
	return (map);
}
