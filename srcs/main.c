/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:11:05 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 12:17:03 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		keyCheck(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == ESC)
	{
		mlx_clear_window(map->mlx, map->window);
		mlx_destroy_window(map->mlx, map->window);
	}
	if (keycode == A)
	{
		map->window = DrawWindow(map->mlx, map->window, "FDF2"); 
	}
	return (0);
}

int		test()
{
	ft_putendl("Weirdo");
	return (1);
}

int		main(void)
{
	t_map	*map;

	map = ft_memalloc(sizeof(map));
	map->window = NULL;
	map->mlx = NULL;
	if (!(map->window = DrawWindow(map->mlx, map->window, "FDF")))
		return (0);
	mlx_key_hook(map->window, keyCheck, (void*)&map);
	mlx_loop(map->window);
	return (0);
}
