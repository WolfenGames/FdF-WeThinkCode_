/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:05:47 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 08:05:48 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     loop_hook(t_map *map)
{
    mlx_do_key_autorepeaton(map->mlx);
    center(map, map->curr_width, map->curr_height);
	mlx_hook(map->window, 2, 1L << 0, keyhook, map); 
    return (0);
}