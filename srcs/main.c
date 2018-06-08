/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:29:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 08:11:52 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map			mapini(t_map *map)
{
	map->scale = 10;
	map->map_x = 0; 
	map->map_y = 0;
	map->map_z = 0;
	return (*map);
}

int				main(int ac, char **argv)
{
	t_map		map;

	ft_putendl("Welcome to the Jungle");
	map = mapini(&map);
	map = loadMap(ac, argv, &map);
	mapify(&map, &map.points);
	map_init(&map);
	return (0);
}
