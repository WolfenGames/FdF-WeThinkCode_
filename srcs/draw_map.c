/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:18:29 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 12:27:28 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	debug_strings(t_map map)
{
	mlx_string_put(map.mlx, map.window, 10, 10, C_BLUE,
			ft_strjoin("Pixels :: ", ft_itoa(map.height * map.width)));
	mlx_string_put(map.mlx, map.window, 10, 30, C_GREEN,
			ft_strjoin("Pos X  :: ", ft_itoa(map.map_x)));
	mlx_string_put(map.mlx, map.window, 10, 50, C_GREEN,
			ft_strjoin("Pos Y  :: ", ft_itoa(map.map_y)));
	mlx_string_put(map.mlx, map.window, 10, 70, C_GREEN,
			ft_strjoin("Pos Z  :: ", ft_itoa(map.map_z)));
	mlx_string_put(map.mlx, map.window, 10, 90, C_RED,
			ft_strjoin("Map H  :: ", ft_itoa(map.height)));
	mlx_string_put(map.mlx, map.window, 10, 110, C_RED,
			ft_strjoin("Map W  :: ", ft_itoa(map.width)));
	mlx_string_put(map.mlx, map.window, 10, 130, C_RED,
			ft_strjoin("Scale_x:: ", ft_itoa(map.scale_x)));
	mlx_string_put(map.mlx, map.window, 10, 150, C_RED,
			ft_strjoin("Scale_y:: ", ft_itoa(map.scale_y)));
	mlx_string_put(map.mlx, map.window, 10, 170, C_RED,
			ft_strjoin("scale_z:: ", ft_itoa(map.scale_z)));
}

void	line(t_points p1, t_points p2, t_map *map)
{
	float		steps;
	float		i;
	t_points	sum;
	int			col;
	i = 0;
	steps = (float)pow((fmax(
					fabs((float)(p2.x - p1.x)),
					fabs((float)(p2.z - p1.z)))), -1);
	if (p2.col == 1 && p1.col == 1)
		col = C_RED;
	else
		col = C_GREEN;
	while (i <= 1)
	{
		sum.x = p1.x + i * (p2.x - p1.x);
		sum.z = p1.z + i * (p2.z - p1.z);
		mlx_pixel_put(map->mlx, map->window, sum.x ,sum.z , col);
		i += steps;
	}
}

void	display(t_map map)
{
	int		i;
	int		j;

	i = 0;
	debug_strings(map);
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (i < map.s_h && j < map.s_w)
			{
				if (i + 1 < map.height)
					line(map.points[i][j], map.points[i + 1][j], &map);
				if (j + 1 < map.width)
					line(map.points[i][j], map.points[i][j + 1], &map);
			}
			j++;
		}
		i++;
	}
}
