/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:05:15 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/12 10:05:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int         get_color_value(const char *s)
{
    (void)s;
    return (0xffffff);
}

t_points    new_point(int x, char *y, int z, t_map *m)
{
    t_points    p;
    
    p.x = x;
    p.y = ft_atoi(y);
    p.z = z;
    p.m = (p.y != 0) ? TRUE : FALSE;
    if (p.m)
        p.y += m->mv_z;
    return (p);
}

void    free_points(t_map *m, t_points **p)
{
    long int    i;

    i = -1;
    while (++i < m->h)
    {
        free(p[i]);
    }
    free(p);
    p = NULL;
}

void    mapify(t_map *m, t_points ***p)
{
    long int    x;
    long int    y;
    char        **sp;
    t_points    **np;

    x = 0;
    np = (t_points **)malloc(sizeof(t_points) * m->h);
    while (x < m->h)
    {
        np[x] = (t_points *)malloc(sizeof(t_points) * m->w);
        y = 0;
        sp = ft_strsplit(m->m[x], ' ');
        while (y < m->w)
        {
            if (!sp[y])
                break ;
            np[x][y] = new_point(x, sp[y], y, m);
            free(sp[y]);
            y++;
        }
        free(sp);
        x++;
    }
    *p = np;
}
