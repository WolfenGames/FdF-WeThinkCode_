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
    p.y = y;
    p.z = z;
    p.m = FALSE;
    p.c = 0x0000FF;
    return (p);
}

void    mapify(t_map *m, t_points ***p)
{
    long int    i;
    long int    l;
    char        **sp;
    t_points    **np;

    i = 0;
    np = (t_points **)malloc(sizeof(t_points) * m->h);
    while (i < m->h)
    {
        np[i] = (t_points *)malloc(sizeof(t_points) * m->w);
        l = 0;
        sp = ft_strsplit(m->m[i], ' ');
        while (l < m->w)
        {
            np[i][l] = new_point(i * m->scl, ft_atoi(sp[l]) * m->scl, l* m->scl, m);
            l++;
        }
        free(sp);
        i++;
    }
    *p = np;
}
