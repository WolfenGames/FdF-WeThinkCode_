/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:05:15 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/12 10:05:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		ft_char_toupper(char c)
{
	int		ic;

	ic = ft_toupper(c);
	return (ic);
}

t_points	new_point(int x, char *y, int z, t_map *m)
{
	t_points	p;
	char		*found;
	char		*t;

	p.z = x - (m->h / 2);
	p.y = ft_atoi(y);
	p.x = z - (m->w / 2);
	found = ft_strchr(y, 'x');
	if (found)
	{
		t = ft_strmap(found + 1, ft_char_toupper);
		p.c = ft_atoi_base(t, 16);
		free(t);
	}
	else if (p.y < 9)
		p.c = (p.y > 1) ? 0xFF00FF : 0xFFFF00;
	else
		p.c = (p.y > 9) ? 0x00FF00 : 0x0000FF;
	return (p);
}

void		escape_mapify(void)
{
	ft_putendl(ESCAPE_YODA);
	exit(11);
}

void		mapify(t_map *m, t_points ***p)
{
	long int	x;
	long int	y;
	char		**sp;
	t_points	**np;

	x = 0;
	np = (t_points **)malloc(sizeof(t_points) * m->h);
	while (x < m->h)
	{
		np[x] = (t_points *)malloc(sizeof(t_points) * m->w);
		y = 0;
		sp = ft_strsplit(m->m[x], ' ');
		while (y < m->w)
		{
			if (ft_strlen(sp[y]) == 0)
				escape_mapify();
			np[x][y] = new_point(x, sp[y], y, m);
			free(sp[y]);
			y++;
		}
		free(sp);
		x++;
	}
	*p = np;
}
