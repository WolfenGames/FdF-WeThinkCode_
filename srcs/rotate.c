/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:42:29 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/25 11:42:31 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_points    rot_x(float angle, t_points p)
{
    t_points    np;

    angle = angle * (M_PI / 180);
    np.z = p.z * cos(angle) - p.y * sin(angle);
    np.y = p.y * cos(angle) + p.z * sin(angle);
    np.x = p.x;
    return (np);
}

t_points    rot_y(float angle, t_points p)
{
    t_points    np;

    angle = angle * (M_PI / 180);
    np.x = p.z * cos(angle) + p.x * sin(angle);
    np.z = p.x * cos(angle) - p.z * sin(angle);
    np.y = p.y;
    return (np);
}

t_points    rot_z(float angle, t_points p)
{
    t_points    np;

    angle = angle * (M_PI / 180);
    np.x = p.y * cos(angle) - p.x * sin(angle);
    np.y = p.y * sin(angle) + p.x * cos(angle);
    np.z = p.z;
    return (np);
}

void    do_rot(t_map *map)
{
    int     i;
    int     j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            MP[i][j] = rot_x(1, MP[i][j]);
            MP[i][j] = rot_y(1, MP[i][j]);
            MP[i][j] = rot_y(1, MP[i][j]);
            j++;
        }
        i++;
    }
    center(map, map->curr_width + map->move_x, map->curr_height + map->move_z);
}