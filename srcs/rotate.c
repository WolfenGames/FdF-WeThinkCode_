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

void    rot_x(float angle, t_map *map)
{
    int     i;
    int     j;
    float   y1;
    float   z1;

    i = 0;
    angle = angle * (M_PI / 180);
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            y1 = map->points[i][j].z * cos(angle) - map->points[i][j].y * sin(angle);
            z1 = map->points[i][j].y * cos(angle) + map->points[i][j].z * sin(angle);
            map->points[i][j].z = z1;
            map->points[i][j].y = y1;
            j++;
        }
        i++;
    }
}

void    rot_y(float angle, t_map *map)
{
    int     i;
    int     j;
    float   x1;
    float   z1;

    i = 0;
    angle = angle * (M_PI / 180);
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            x1 = map->points[i][j].z * cos(angle) + map->points[i][j].x * sin(angle);
            z1 = map->points[i][j].x * cos(angle) - map->points[i][j].z * sin(angle);
            map->points[i][j].z = z1;
            map->points[i][j].x = x1;
            j++;
        }
        i++;
    }
}

void    rot_z(float angle, t_map *map)
{
    int     i;
    int     j;
    float   x1;
    float   y1;

    i = 0;
    angle = angle * (M_PI / 180);
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            x1 = map->points[i][j].y * cos(angle) - map->points[i][j].x * sin(angle);
            y1 = map->points[i][j].y * sin(angle) + map->points[i][j].x * cos(angle);
            map->points[i][j].x = x1;
            map->points[i][j].y = y1;
            j++;
        }
        i++;
    }
}
