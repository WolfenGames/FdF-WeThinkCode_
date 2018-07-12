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
    *m = load_file(m_n, m);
    mapify(m, &m->pnts);
    draw(m);
    mlx_hook(m->win, 17, 0, buttonhook, m);
    mlx_hook(m->win, 2, 0, keyhook, m);
    mlx_loop(m->mlx);
}
