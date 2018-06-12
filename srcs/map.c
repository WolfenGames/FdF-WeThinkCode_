/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:31:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 12:01:28 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	center(t_map *map)
{
	int		i;
	int		j;
	int		off_x;
	int		off_y;

	i = 0;
	off_x = map->points[map->height / 2][map->width / 2].x;
	off_y = map->points[map->height / 2][map->width / 2].z;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x -= off_x;
			map->points[i][j].x += map->s_w / 2;
			map->points[i][j].z -= off_y;
			map->points[i][j].z += map->s_h / 2;
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *map)
{
	t_map	mapcpy;

	mlx_clear_window(map->mlx, map->window);
	mapcpy = *map;
	mapcpy.points = simulacron(map);
	rot_x(map->rot_x, &mapcpy);
	rot_y(map->rot_y, &mapcpy);
	rot_z(map->rot_z, &mapcpy);
	scale_map(&mapcpy);
	move_map(&mapcpy);
	free_points(mapcpy);
	center(map);
	display(*map);
}

int		mousehook(int button, int x, int y, t_map *map)
{
	if (button == 4)
		map->rot_y += ANGL;
	if (button == 5)
		map->rot_y -= ANGL;
	if (button == 6)
		map->rot_x -= ANGL;
	if (button == 7)
		map->rot_x += ANGL;
 	rot_x(map->rot_x, map);
	rot_y(map->rot_y, map);
	rot_z(map->rot_z, map); 
	draw_map(map);
	return (0);
}

void	map_init(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, DEF_W, DEF_H, "FDF - Standard");
	map->s_w = DEF_W;
	map->s_h = DEF_H;
	map->scale_x = 1;
	map->scale_y = 1;
	map->scale_z = 1;
	map->rot_x = ANGL;
	map->rot_y = ANGL;
	map->rot_z = ANGL;
	map->move_x = 0;
	map->move_y = 0;
	map->move_z = 0;
	rot_x(map->rot_x, map);
	rot_y(map->rot_y, map);
	rot_z(map->rot_z, map);
	draw_map(map);
	mlx_hook(map->window, 2, 1L << 0, keyhook, map);
//	mlx_hook(map->window, 4, 1L << 8 , mousehook, map);
	mlx_loop(map->mlx);
}
