/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:11:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/11 16:11:02 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     get_color(int seed)
{
    int     r;
    int     g;
    int     b;

    r = ft_rand(0, 255, seed);
    g = ft_rand(0, 255, seed);
    b = ft_rand(0, 255, seed);
    return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
