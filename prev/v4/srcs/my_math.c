/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:21:06 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 07:21:34 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float   v2_distance(float x1, float y1, float x2, float y2)
{
    float   distance;
    float   x;
    float   y;

    distance = 0;
    x = ft_power_f((x2 - x1), 2);
    y = ft_power_f((y2 - y1), 2);
    distance = ft_sqrt_f(x + y);
    return (distance);
}
