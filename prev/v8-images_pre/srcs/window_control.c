/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcontrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:20:37 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 13:20:40 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	new_image(t_map *map)
{
	if (map->img != NULL)
		mlx_destroy_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->curr_width, map->curr_height);
	map->data = mlx_get_data_addr(map->img, &map->bpp, &map->sl, &map->endian);
	map->bpp /= 8;
}

void	window_new(int keycode, t_map *map)
{
	if (keycode == NUM_PLUS)
	{
		mlx_destroy_window(map->mlx, map->window);
		map->window = mlx_new_window(map->mlx, MAX_W, MAX_H, "FdF - MAX");
		center(map, MAX_W, MAX_H);
		map->curr_height = MAX_H;
		map->curr_width = MAX_W;
		new_image(map);
		display(map);
		mlx_hook(map->window, 2, 1L << 0, keyhook, map);
	}
	else if (keycode == NUM_MINUS)
	{
		mlx_destroy_window(map->mlx, map->window);
		map->window = mlx_new_window(map->mlx, DEF_W, DEF_H, "FdF - MIN");
		center(map, DEF_W, DEF_H);
		map->curr_width = DEF_W;
		map->curr_height = DEF_H;
		new_image(map);
		display(map);
		mlx_hook(map->window, 2, 1L << 0, keyhook, map);
	}
}

void	escape(void)
{
	ft_putendl("Thank you for playing Jumanji Beta version... early beta");
	exit(0);
}
