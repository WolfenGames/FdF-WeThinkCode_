/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:11:05 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 15:33:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		main(int ac, char **argv)
{
	t_map	*map;

	if(!(map = ft_memalloc(sizeof(map))))
		return (1);
	map = newMap(map);
	if (ac == 2)
	{
		LoadMap(argv[1], map);
		DrawWindow(map);
		HandleInput(map);
		DrawMap(map);
		mlx_loop(map->mlx);
	}
	return (0);
}
