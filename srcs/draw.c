/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:27:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 15:27:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    new_image(t_map *m)
{
    m->img = mlx_new_image(m->mlx, m->wi.c_w, m->wi.c_h);
    m->dat = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endn);
    m->bpp /= 8;
}

void    put_pixel(int x, int y, int col, t_map *m)
{
    x += m->mv_x;
    y += m->mv_y;
    if (x >= 0 && y >= 0 && y < m->wi.c_h && x < m->wi.c_w)
        *(unsigned int *)(m->dat + (x * m->bpp) + (y * m->sl)) = col;
}

int    draw(t_map *m)
{
    int     xc;
    int     x;
    int     yc;
    int     y;

    xc = m->wi.c_w / 2;
    yc = m->wi.c_h / 2;
    new_image(m);
    x = 0;
    while (x++ < 850)
    {
        y = 0;
        while (y++ < 500)
        {
            put_pixel(x * m->scl, y * m->scl, 0xFF00FF, m);
        }
        x++;
    }
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    return (0);
}
