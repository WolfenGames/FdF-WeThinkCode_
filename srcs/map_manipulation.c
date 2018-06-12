/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 07:10:48 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/12 07:19:12 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    scale_map(t_map *map)
{
    t_points    **new;
    t_points    hold;
    char        **strsplit;
    int         i;
    int         j;
    int         y;

    i = 0;
    new = (t_points **)malloc(sizeof(t_points *) * map->height);
    if (map->scale_x > 1 || map->scale_y > 1 || map->scale_z > 1)
    {
        while (i < map->height)
        {
            new[i] = (t_points *)malloc(sizeof(t_points) * map->width);
            strsplit = ft_strsplit(map->map[i], ' ');
            j = 0;
            while (j < map->width)
            {
                y = ft_atoi(strsplit[j]) * map->scale_y;
                hold = map->points[i][j];
                new[i][j] = new_point(hold.x * (map->scale_x),
                        y,
                        hold.z * (map->scale_z));
                j++;
            }
            free(strsplit);
            i++;
        }
        free_points(*map);
        map->points = new;
        center(map);
    }else if (map->scale_x < 0 || map->scale_y < 0 || map->scale_z < 0)
    {
        i = 0;
        new = (t_points **)malloc(sizeof(t_points *) * map->height);
        while (i < map->height)
        {
            new[i] = (t_points *)malloc(sizeof(t_points) * map->width);
            strsplit = ft_strsplit(map->map[i], ' ');
            j = 0;
            while (j < map->width)
            {
                y = ft_atoi(strsplit[j]);
                new[i][j] = map->points[i][j];
                new[i][j].x /= -(map->scale_x);
                new[i][j].y = y;
                new[i][j].z /= -(map->scale_z);
                j++;
            }
            i++;
        }
        free_points(*map);
        map->points = new;
        center(map);
    }
    map->scale_x = 1;
    map->scale_y = 1;
    map->scale_z = 1;
}

void    move_map(t_map *map)
{
    int     i;
    int     j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            map->points[i][j].x += map->move_x;
            map->points[i][j].y += map->move_y;
            map->points[i][j].z += map->move_z;
            j++;
        }
        i++;
    }
    map->map_x += map->move_x;
    map->map_y += map->move_y;
    map->map_z += map->move_z;
    map->move_x = 0;
    map->move_y = 0;
    map->move_z = 0;
}