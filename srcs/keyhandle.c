/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:54:12 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 14:54:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(t_map *m)
{
	rot_x(m->r_x, m);
	rot_y(m->r_y, m);
	rot_z(m->r_z, m);
}

int		rot(int keycode, t_map *m)
{
	if (keycode == NUM_1)
		rot_y(10, m);
	if (keycode == NUM_3)
		rot_y(-10, m);
	if (keycode == NUM_2)
		rot_x(10, m);
	if (keycode == NUM_8)
		rot_x(-10, m);
	if (keycode == NUM_6)
		rot_z(-10, m);
	if (keycode == NUM_4)
		rot_z(10, m);
	return (0);
}

int		key_press_hook(int keycode, t_map *m)
{
	if (keycode == ESC)
		exit_hook(keycode, m);
	if (keycode == ARROW_LEFT || keycode == A)
		m->mv_x -= 10;
	if (keycode == ARROW_RIGHT || keycode == D)
		m->mv_x += 10;
	if (keycode == ARROW_UP || keycode == W)
		m->mv_y -= 10;
	if (keycode == ARROW_DOWN || keycode == S)
		m->mv_y += 10;
	if (keycode == NUM_PLUS)
		m->scl *= 2.f;
	if (keycode == NUM_MINUS && m->scl > 0.01)
		m->scl *= 0.5f;
	rot(keycode, m);
	draw(m);
	return (0);
}

int		exit_hook(int keycode, t_map *m)
{
	(void)m;
	(void)keycode;
	exit(0);
	return (0);
}
