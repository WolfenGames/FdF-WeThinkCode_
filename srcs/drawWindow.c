/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawWindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:12:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 16:42:03 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*DrawWindow(t_win *win)
{
	ft_putendl("Iniating the mlx");
	if (!(win->mlx = mlx_init()))
		return (NULL);
	ft_putendl("Done.\n Iniating the Window");
	win->window = mlx_new_window(win->mlx, DEF_W, DEF_H, "FDF");
	ft_putendl("Done.\n Returning Map");
	return (win);
}
