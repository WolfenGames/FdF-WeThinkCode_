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
    if (x > 0 && x < m->wi.c_w && y > 0 && y < m->wi.c_h)
        *(unsigned int *)(m->dat + (x * m->bpp) + (y * m->sl)) = col;
}

void    line(t_points p1, t_points p2, t_map *m)
{
    double      s;
    double      i;
    int         j;
    t_points    sum;

    i = 0;
    j = 0;
    s = (float)pow(fmax(
                fabs((double)(p1.x - p2.x)),
                fabs((double)(p1.z - p2.z))), -1);
    while (i <= 1)
    {
        sum.x = p1.x + i * (p2.x - p1.x);
        sum.z = p1.z + i * (p2.z - p1.z);
        if (j % 2 == 0)
            put_pixel(sum.x, sum.z, 0x00FF00, m);
        if (j % 3 == 0)
            put_pixel(sum.x, sum.z, 0xFF0000, m);
        if (j % 4 == 0)
            put_pixel(sum.x, sum.z, 0x0000FF, m);
        i += s;
        j++;
    }
}

void    show_map(int x, int y, t_map *m)
{
    int     i;
    int     j;

    i = 0;
    while (i < m->w)
    {
        j = 0;
        while (j < m->h)
        {
            put_pixel(i + x, j + y, 0x0000FF, m);
            j++;
        }
        i++;
    }
}

int     draw(t_map *m)
{
    int  x;
    int  y;

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
