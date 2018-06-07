/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:36:11 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 11:21:20 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	get_map(t_map *map)
{
	map->map_x = 0;
	map->map_y = 0;
	map->scale = 1;
	map->width = 20;
	map->height = 20;
	if (!map)
		ft_putendl("FUCKED");
	return (*map);
}
