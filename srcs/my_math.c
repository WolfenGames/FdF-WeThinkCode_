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
    x = pow((x2 - x1), 2);
    y = pow((y2 - y1), 2);
    distance = sqrtā(x + y);
    return (distance);
}
