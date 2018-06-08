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
			ft_strjoin("Scale  :: ", ft_itoa(map.scale)));
	mlx_string_put(map.mlx, map.window, 10, 50, C_GREEN,
			ft_strjoin("Pos X  :: ", ft_itoa(map.map_x)));
	mlx_string_put(map.mlx, map.window, 10, 70, C_GREEN,
			ft_strjoin("Pos Y  :: ", ft_itoa(map.map_y)));
	mlx_string_put(map.mlx, map.window, 10, 90, C_GREEN,
			ft_strjoin("Pos Z  :: ", ft_itoa(map.map_z)));
	mlx_string_put(map.mlx, map.window, 10, 110, C_RED,
			ft_strjoin("Map H  :: ", ft_itoa(map.height)));
	mlx_string_put(map.mlx, map.window, 10, 130, C_RED,
			ft_strjoin("Map W  :: ", ft_itoa(map.width)));
}

void	line(t_points p1, t_points p2, t_map *map)
{
	float		steps;
	float		i;
	int			col;
	t_points	sum;

	i = 0;
	col = C_GREEN;
	steps = (float)pow((fmax(
					fabs((double)(p1.x - p2.x)),
					fabs((double)(p1.z - p2.z)))), -1);
	while (i <= 1)
	{
		sum.x = p1.x + i * (p2.x - p1.x);
		sum.z = p1.z + i * (p2.z - p1.z);
/*		mlx_pixel_put(map->mlx, map->window,
				(DEF_W / 2) + map->map_x + sum.x,
				(DEF_H / 2) + map->map_z + sum.z
				, p1.col);
*/
		mlx_pixel_put(map->mlx, map->window, sum.x, sum.z, p1.col);
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
			if (i + 1 < map.height)
				line(map.points[i][j], map.points[i + 1][j], &map);
			if (j + 1 < map.width)
				line(map.points[i][j], map.points[i][j + 1], &map);
			j++;
		}
		i++;
	}
}
