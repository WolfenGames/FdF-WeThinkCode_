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

void		rot_x(float angle, t_map *m)
{
	int		i;
	int		j;
	float	y1;
	float	z1;

	i = 0;
	angle = angle * (M_PI / 180);
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			y1 = m->pnts[i][j].y * cos(angle) - m->pnts[i][j].z * sin(angle);
			z1 = m->pnts[i][j].z * cos(angle) + m->pnts[i][j].y * sin(angle);
			m->pnts[i][j].z = z1;
			m->pnts[i][j].y = y1;
			j++;
		}
		i++;
	}
}

void		rot_y(float angle, t_map *m)
{
	int		i;
	int		j;
	float	x1;
	float	z1;

	i = 0;
	angle *= M_PI / 180;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			x1 = m->pnts[i][j].x * cos(angle) + m->pnts[i][j].z * sin(angle);
			z1 = m->pnts[i][j].z * cos(angle) - m->pnts[i][j].x * sin(angle);
			m->pnts[i][j].z = z1;
			m->pnts[i][j].x = x1;
			j++;
		}
		i++;
	}
}

void		rot_z(float angle, t_map *m)
{
	int		i;
	int		j;
	float	x1;
	float	y1;

	i = 0;
	angle = angle * (M_PI / 180);
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			x1 = m->pnts[i][j].x * cos(angle) - m->pnts[i][j].y * sin(angle);
			y1 = m->pnts[i][j].x * sin(angle) + m->pnts[i][j].y * cos(angle);
			m->pnts[i][j].x = x1;
			m->pnts[i][j].y = y1;
			j++;
		}
		i++;
	}
}
