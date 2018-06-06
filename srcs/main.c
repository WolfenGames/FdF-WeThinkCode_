/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:11:05 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 16:40:57 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		main(int ac, char **argv)
{
	t_map	*map;
	t_win	*win;

	if (!(win = ft_memalloc(sizeof(t_win))))
		return (0);
	if(!(map = ft_memalloc(sizeof(t_map))))
		return (0);
	map = newMap(map);
	if (ac == 2)
	{
		LoadMap(argv[1], map);
	}
	DrawWindow(win);
	HandleInput(win, map);
	DrawMap(win);
	mlx_loop(win->mlx);
	return (0);
}
