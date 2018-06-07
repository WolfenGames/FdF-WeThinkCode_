/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:27:41 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 17:31:49 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_debug(t_win *win, t_map *map)
{	
	mlx_string_put(win->mlx, win->window, 10, 10, RED, map->map);
}