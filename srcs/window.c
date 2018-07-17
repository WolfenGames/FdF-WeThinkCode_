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

void	set_hooks(t_map *m)
{
	mlx_do_key_autorepeaton(m->mlx);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	mlx_hook(m->win, 17, 0, exit_hook, m);
}

void    window_init(char *m_n)
{
    t_map   *m;

    m = (t_map *)malloc(sizeof(t_map));
    m->wi.wn = "Fdf - Win";
    m->wi.c_h = DEF_H;
    m->wi.c_w = DEF_W;
    m->mlx = mlx_init();
    m->win = mlx_new_window(m->mlx, m->wi.c_w, m->wi.c_h, m->wi.wn);
    load_file(m_n, m);
    m->m_z = 0;
    m->r_x = 0;
    m->r_y = 0;
    m->r_z = 0;
    mapify(m, &m->pnts);
    m->scl = 20;
    m->mv_x = 0;//(m->wi.c_w / 2) - ((m->w) * m->scl)/2;
    m->mv_y = 0;//(m->wi.c_h / 2) - ((m->h) * m->scl)/2;
    m->mv_z = 0;
    rotate(m);
    draw(m);
    set_hooks(m);
    mlx_loop(m->mlx);
}
