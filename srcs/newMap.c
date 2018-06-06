/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:07:44 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 16:32:05 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*newMap(t_map *map)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = 0;
	point->y = 0;
	ft_putendl("Making a x");
	map->pos.x = 0;
	ft_putendl("Made a x");
	map->points = point;
	free(point);
	return (map);
}
