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

t_points    new_point(int x, int y, int z, t_map *m)
{
    t_points p;
    
    p.x = x;
    p.y = -y;
    p.z = z;
    p.m = (y > 1) ? TRUE : FALSE;
    p.c = 0x0000000;
    return (p);
}

void    free_points(t_map map)
{
    long int    i;

    i = -1;
    while (++i < map.h)
    {
        free(map.pnts[i]);
    }
    free(map.pnts);
    map.pnts = NULL;
}

void    mapify(t_map *m, t_points ***p)
{
    long int    x;
    long int    y;
    char        **sp;
    t_points    **np;
    t_points    *t;

    x = 0;
    np = (t_points **)malloc(sizeof(t_points) * m->h);
    while (x < m->h)
    {
        np[x] = (t_points *)malloc(sizeof(t_points) * m->w);
        y = 0;
        sp = ft_strsplit(m->m[x], ' ');
        while (y < m->w)
        {
            np[x][y] = new_point(x * m->scl, ft_atoi(sp[y]) * (m->scl / 4), y * m->scl,  m);
            y++;
        }
        free(sp);
        x++;
    }
    *p = np;
}
