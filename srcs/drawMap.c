/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:18:29 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 11:34:27 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	plotpoints(t_map *map, int xx, int yy)
{
	int	 	x;
	int		y;
	int		holdx;
	int		holdy;
	int		scale;
	
	scale = map->scale;
	holdx = (map->width * scale) / 2;
	holdy = (map->height * scale) / 2;
	x = -holdx;
	y = -holdy;
	mlx_string_put(map->mlx, map->window, 10, 10, C_RED, "FDF - IS KAK");
	mlx_string_put(map->mlx, map->window, 10, 40,
			C_GREEN, ft_itoa(map->scale));
	while (x < holdx)
	{
		while (y < holdy)
		{
			mlx_pixel_put(map->mlx, map->window, (DEF_W / 2) + xx + x,
					(DEF_H / 2) + yy + y, C_GREEN);
			y += scale;
		}
		y = -holdy;
		x += scale;
	}
}
