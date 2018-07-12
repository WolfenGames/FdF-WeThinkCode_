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
    *(unsigned int *)(m->dat + (x * m->bpp) + (y * m->sl)) = col;
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
    double  x;
    double  y;

    new_image(m);
    x = 0;
    while (x < m->h)
    {
        y = 0;
        while (y < m->w)
        {
            put_pixel(x, y, 0x0000FF, m);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    mlx_destroy_image(m->mlx, m->img);
    return (0);
}
