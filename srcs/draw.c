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

void    put_pixel(float x, float y, int col, t_map *m)
{
    x += m->mv_x;
    y += m->mv_y;
    if (x > 0 && x < m->wi.c_w && y > 0 && y < m->wi.c_h)
    {
        *(unsigned int *)(m->dat + ((int)x * m->bpp) + ((int)y * m->sl)) = col;
    }
}

void    line(t_points p1, t_points p2, t_map *m)
{
    double      s;
    double      i;
    t_points    sum;

    i = 0;
    p1.x *= m->scl;
    p1.z *= m->scl;
    p2.x *= m->scl;
    p2.z *= m->scl;
    s = (float)pow(fmax(
                fabs((double)(p1.x - p2.x)),
                fabs((double)(p1.z - p2.z))), -1);
    while (i <= 1)
    {
        sum.x = p1.x + i * (p2.x - p1.x);
        sum.z = p1.z + i * (p2.z - p1.z);
        if (!p2.m && !p1.m)
        {
            put_pixel(sum.x, sum.z, 0xFF00FF, m);
        }
        else if (p1.m && p2.m)
        {
            put_pixel(sum.x, sum.z, 0x00FF00, m);
        }
        else
        {
            int     r;
            int     b;
            int     g;
            int     col;

            r = (i/1) * 125;
            g = (i/1) * 200;
            b = (i/1) * 100;
            col = (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
            put_pixel(sum.x, sum.z, col, m);
        }
        i += s;
    }
}

int     draw(t_map *m)
{
    int  x;
    int  y;

    mlx_clear_window(m->mlx, m->win);
    new_image(m);
    x = 0;
    while (x < m->h)
    {
        y = 0;
        while (y < m->w)
        {
            if (x + 1 < m->h)
                line(m->pnts[x][y], m->pnts[x + 1][y], m);
            if (y + 1 < m->w)
                line(m->pnts[x][y], m->pnts[x][y + 1], m);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    mlx_destroy_image(m->mlx, m->img);
    return (0);
}
