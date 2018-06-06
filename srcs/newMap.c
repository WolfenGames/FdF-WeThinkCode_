/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:07:44 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 15:31:20 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*newMap(t_map *map)
{
	t_point		*point;
	t_pos		*pos;

	point = ft_memalloc(sizeof(t_point));
	pos	= ft_memalloc(sizeof(t_pos));
	map->pos = pos;
	map->points = point;
	free(point);
	free(pos);
	return (map);
}
