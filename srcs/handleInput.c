/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleInput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:39:27 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 13:34:47 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		getKeys(int keycode, void *params)
{
	t_map	*map;

	map = (void *)params;
	handleExit(keycode);
	moveCamera(keycode, map);
	rotCamera(keycode, map);
	scaleMap(keycode, map);
	zoomMap(keycode, map);
	return (0);
}

void	HandleInput(t_map *map)
{
	mlx_key_hook(map->window, getKeys, (void *)&map);
}
