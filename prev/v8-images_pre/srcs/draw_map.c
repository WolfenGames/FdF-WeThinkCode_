/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:18:29 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/29 14:31:44 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line(t_points p1, t_points p2, t_map *map)
{
	double		steps;
	double		i;
	int			col;
	t_points	sum;

	i = 0;
	if (ft_distance(p1, p2) < -1 && p2.move && p1.move)
		col = p1.col;
	else if (ft_distance(p1, p2) > 1 && p2.move && p1.move)
		col = p2.col;
	else
		col = 0xFFF00FF;
	steps = (float)pow((fmax(
					fabs((double)(p1.x - p2.x)),
					fabs((double)(p1.z - p2.z)))), -1);
	if (p1.x > map->curr_width && p1.x < 0 && p2.x > map->curr_height && p2.x < 0)
	{
		map->pixels--;
		return ;
	}
	if (p2.y > map->curr_height && p1.x < 0 && p2.y > map->curr_height && p2.y < 0)
	{
		map->pixels--;
		return ;
	}
	while (i <= 1)
	{
		sum.x = p1.x + i * (p2.x - p1.x);
		sum.z = p1.z + i * (p2.z - p1.z);
		*(unsigned int *)(map->data + ((int)sum.x * map->bpp) +
			((int)sum.y * map->sl)) = col;
		map->pixels++;
		i += steps;
	}
}

void	put_pixel(int x, int y, t_map *map)
{
	if ((x < map->curr_height) && (y < map->curr_width))
		*(unsigned int *)(map->data + (x * map->bpp) + (y * map->sl)) =
			get_color(x + y + 1);
}

void	display(t_map *map)
{
	int		i;
	int		j;

	map->pixels = 0;
	new_image(map);
	i = 0;
	while (i < map->curr_width)
	{
		j = 0;
		while (j < map->curr_height)
		{
			/* if (i + 1 < map->height)
				line(map->points[i][j], map->points[i + 1][j], map);
			if (j + 1 < map->width)
				line(map->points[i][j], map->points[i][j + 1], map); */
			put_pixel(i, j, map);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->window, map->img, 0, 0);
}
