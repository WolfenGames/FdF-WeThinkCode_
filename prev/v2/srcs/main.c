/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:29:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 17:54:01 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map			mapini(t_map *map)
{
	map->height = 1;
	map->width = 1;
	map->scale = 10;
	map->map_x = 0;
	map->map_y = 0;
	map->map_z = 0;
	return (*map);
}

int				main(int ac, char **argv)
{
	t_map		map;

	map = mapini(&map);
	map = loadMap(ac, argv, &map);
	mapify(&map, &map.points);
	map_init(&map);
	return (0);
}
