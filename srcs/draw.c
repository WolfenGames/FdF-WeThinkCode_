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

int     colour_grad(int col1, int col2, float r)
{
    float   b_col1[3];
    float   b_col2[3];
    int     ret;

    b_col1[0] = (col1 & 0xff0000) / 0x10000;
    b_col1[1] = (col1 & 0xff00) / 0x100;
    b_col1[2] = (col1 & 0xff);

    b_col2[0] = (col2 & 0xff0000) / 0x10000;
    b_col2[1] = (col2 & 0xff00) / 0x100;
    b_col2[2] = (col2 & 0xff);
    ret = b_col2[0] * r + b_col1[0] * (1 - r);
    ret *= 0x100;
    ret += b_col2[1] * r + b_col1[1] * (1 - r);
    ret *= 0x100;
    ret += b_col2[2] * r + b_col1[2] * (1 - r);
    return (ret);
}

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
        put_pixel(sum.x, sum.z, colour_grad(p1.c, p2.c, i), m);
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
