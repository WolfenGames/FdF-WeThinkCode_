/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:34:39 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 16:47:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		printdata(int keycode)
{
		ft_putendl(ft_itoa(keycode));
}

int		handleExit(int keycode)
{
	if (keycode == ESC)
	{
		exit(0);
	}
	return (0);
}

int		moveCamera(int keycode, t_map *map)
{
	if (!map)
		return (0);
	if (keycode == A || keycode == S || keycode == D || keycode == W)
		printdata(keycode);
	return (0);
}

int		rotCamera(int keycode, t_map *map)
{
	if (!map)
		return (0);
	if (keycode == UP_ARROW || keycode == DOWN_ARROW
			|| keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		printdata(keycode);
	return (0);
}

int		scaleMap(int keycode, t_map *map)
{
	if (!map)
		return (0);
	if (keycode == PG_UP || keycode == PG_DOWN)
		printdata(keycode);
	return (0);
}

int		zoomMap(int keycode, t_map *map)
{
	if (!map)
		return (0);
	if (keycode == NUM_PLUS || keycode == NUM_MINUS)
		printdata(keycode);
	return (0);
}
