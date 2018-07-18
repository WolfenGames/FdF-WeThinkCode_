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
    char *found;

    p.z = x - (m->h / 2);
    p.y = ft_atoi(y);
    p.x = z - (m->w / 2);
    found = ft_strchr(y, 'x');
    if (found)
    {
        p.c = ft_atoi_base(found + 1, 16);
    }
    else
        p.c = (p.y > 1) ? 0xFF00FF : 0xFFFF00;
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
            np[x][y] = new_point(x, sp[y], y, m);
            free(sp[y]);
            y++;
        }
        free(sp);
        x++;
    }
    *p = np;
}
