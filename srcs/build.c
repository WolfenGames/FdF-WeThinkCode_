/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:19:49 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 12:08:10 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		count(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
		if (ft_isdigit(str[i]))
		{
			c++;
			while (ft_isdigit(str[i]) && str[i])
				i++;
		}
		else
			i++;
	return (c);
}

void			mapify(t_map *map, t_points ***poofy)
{
	long int	i;
	long int	l;
	t_points	**new;
	char		**strsplit;

	i = 0;
	map->width = count(map->map[i]);
	new = (t_points **)malloc(sizeof(t_points *) * map->height);
	while (i < map->height)
	{
		new[i] = (t_points *)malloc(sizeof(t_points) * map->width);
		l = 0;
		strsplit = ft_strsplit(map->map[i], ' ');
		while (l < map->width)
		{
			new[i][l] = new_point(i * 20, (ft_atoi(strsplit[l])) * 20, l * 20);
			l++;
		}
		free(strsplit);
		i++;
	}
	*poofy = new;
}

t_points		**simulacron(t_map *map)
{
	long int		i;
	long int		j;
	t_points		**hold;

	i = 0;
	hold = (t_points **)malloc(sizeof(t_points *) * map->height);
	while (i < map->height)
	{
		j = 0;
		hold[i] = (t_points *)malloc(sizeof(t_points) * map->width);
		while (j < map->width)
		{
			hold[i][j] = map->points[i][j];
			j++;
		}
		i++;
	}
	return (hold);
}

void			free_points(t_map map)
{
	long int	i;

	i = -1;
	while (++i < map.height)
		free(map.points[i]);
	free(map.points);
	map.points = NULL;
}
