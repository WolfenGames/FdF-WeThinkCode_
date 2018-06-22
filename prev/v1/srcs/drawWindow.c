/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawWindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:12:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 17:25:07 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*DrawWindow(t_win *win)
{
	if (!(win->mlx = mlx_init()))
		return (NULL);
	win->window = mlx_new_window(win->mlx, DEF_W, DEF_H, "FDF");
	return (win);
}
