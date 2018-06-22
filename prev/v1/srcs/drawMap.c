/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:46:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 08:36:35 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*DrawMap(t_win *win)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x < DEF_W)
	{
		while (y < DEF_H)
		{
			mlx_pixel_put(win->mlx, win->window, x, y, GREEN);
			y++;
		}
		y = 0;
		x++;
	}
	return (win);
}
