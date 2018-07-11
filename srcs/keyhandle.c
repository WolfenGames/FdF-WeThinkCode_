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

int     keyhook(int keycode, t_map *m)
{
    if (keycode == ESC)
        exit(0);
    if (keycode == ARROW_LEFT)
    {
        m->mv_x -= 1;
        draw(m);
    }
    if (keycode == ARROW_RIGHT)
    {
        m->mv_x += 1;
        draw(m);
    }
    if (keycode == ARROW_UP)
    {
        m->mv_y -= 1;
        draw(m);
    }
    if (keycode == ARROW_DOWN)
    {
        m->mv_y += 1;
        draw(m);
    }
    if (keycode == NUM_PLUS)
    {
        m->scl += 1;
        draw(m);
    }
    if (keycode == NUM_MINUS && m->scl > 1)
    {
        m->scl -= 1;
        draw(m);
    }
    return (0);
}

int     buttonhook(int button, t_map *m)
{
    (void)m;
    (void)button;
    exit(0);
    return (0);
}
