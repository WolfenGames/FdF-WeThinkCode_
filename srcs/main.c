/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:29:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 15:20:28 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map	iniMap(t_map *map)
{
	map->height = 1;
	map->width = 1;
	map->scale = 1;
	return (*map);
}

int				main(int ac, char **argv)
{
	t_map		map;

	map = iniMap(&map);
	map = loadMap(ac, argv, &map);
	map_init(&map);
	return (0);
}
