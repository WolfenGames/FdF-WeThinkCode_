/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:08:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 07:08:01 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     map_int(int start, int end, int current, int step)
{
    if (current >= end)
        current = start;
    else
        current += step;
    return (current);
}

float   map_float(float start, float end, float current, float step)
{
    if (current >= end)
        current = start;
    else
        current += step;
    return (current);
}

double map_double(double start, double end, double current, float step)
{
    if (current >= end)
        current = start;
    else
        current += step;
    return (current);
}

size_t map_sizet(size_t start, size_t end, size_t current, size_t step)
{
    if (current >= end)
        current = start;
    else
        current += step;
    return (current);
}