/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:46:52 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 14:46:54 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    window_init(char *m_n)
{
    t_map   *m;

    m = (t_map *)malloc(sizeof(t_map));
    m->wi.wn = "Fdf - Win";
    m->wi.c_h = DEF_H;
    m->wi.c_w = DEF_W;
    m->mlx = mlx_init();
    m->win = mlx_new_window(m->mlx, m->wi.c_w, m->wi.c_h, m->wi.wn);
    m->scl = 20;
    *m = load_file(m_n, m);
    mapify(m, &m->pnts);
    m->mv_x = (m->wi.c_w / 2) - (m->w / 2);
    m->mv_y = (m->wi.c_h / 2) - (m->h / 2);
    m->r_x = 0;
    m->r_y = 0;
    m->r_z = 0;
    m->ang = 60.f;
    rot_x(m->r_x, m);
    rot_y(m->r_y, m);
    rot_z(m->r_z, m);   
    draw(m);
    free_points(*m);
    mlx_hook(m->win, 17, 0, buttonhook, m);
    mlx_hook(m->win, 2, 0, keyhook, m);
    mlx_loop(m->mlx);
}
