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

void    rotate(t_map *m)
{
    rot_x(m->r_x, m);
    rot_y(m->r_y, m);
    rot_z(m->r_z, m);
}

int     rot(t_map *m)
{
//    mapify(m, &m->pnts);
    rotate(m);
    draw(m);
//    free_points(*m);
    return (0);
}

void    reset(t_map *m)
{
    m->r_x = 0;
    m->r_y = -37;
    m->r_z = -22;
    rot(m);
}

int     keyhook(int keycode, t_map *m)
{
    
    if (keycode == ESC)
        exit(0);
    if (keycode == ARROW_LEFT || keycode == A)
        m->mv_x -= m->scl / 2;
    if (keycode == ARROW_RIGHT || keycode == D)
        m->mv_x += m->scl / 2;
    if (keycode == ARROW_UP || keycode == W)
        m->mv_y -= m->scl / 2;
    if (keycode == ARROW_DOWN || keycode == S)
        m->mv_y += m->scl / 2;
    if (keycode == NUM_PLUS)
        m->scl += 0.5f;
    if (keycode == NUM_MINUS && m->scl > 1)
        m->scl -= 0.5f;
    if (keycode == NUM_1)
        m->r_z++;
    if (keycode == NUM_3)
        m->r_z--;
    if (keycode == NUM_2)
        m->r_y++;
    if (keycode == NUM_8)
        m->r_y--;
    if (keycode == NUM_6)
        m->r_x++;
    if (keycode == NUM_4)
        m->r_x--;
    if (keycode == NUM_5)
        reset(m);
    if (keycode == PG_UP)
        m->mv_z++;
    if (keycode == PG_DOWN)
        m->mv_z--;
    rot(m);
    return (0);
}

int     buttonhook(int button, t_map *m)
{
    (void)m;
    (void)button;
    exit(0);
    return (0);
}
