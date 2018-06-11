/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:29:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 11:33:46 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map			*mapini(t_map *map)
{
	map->map_x = 0;
	map->map_y = 0;
	map->map_z = 0;
	map->move_x = 0;
	map->move_y = 0;
	map->move_z = 0;
	map->scale_x = 2;
	map->scale_y = 1;
	map->scale_z = 2;
	map->rot_x = 0;
	map->rot_y = 0;
	map->rot_z = 0;
	map->zoom = 0;
	return (map);
}

int				main(int ac, char **argv)
{
	t_map		map;

	ft_putendl("Welcome to the Jungle");
	map = load_map(ac, argv, &map);
	mapify(&map, &map.points);
	mapify(&map, &map.og_points);
	map_init(&map);
	return (0);
}
