/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawWindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:12:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 11:37:33 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*DrawWindow(void *mlx, void *window, char *title)
{
	if (!(mlx = mlx_init()))
		return (NULL);
	window = mlx_new_window(mlx, DEF_W, DEF_H, title);
	ft_putendl("Created Windows");
	return (window);
}
