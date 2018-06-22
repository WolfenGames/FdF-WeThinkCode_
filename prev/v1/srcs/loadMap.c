/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:41:30 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 17:22:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*LoadMap(char *file, t_map *map)
{
	int		fd;
	char	**line;
	int		i;

	i = 0;
	line = ft_memalloc(sizeof(char **));
	map->map = ft_memalloc(sizeof(char **));
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, line))
	{
		map->map = ft_strjoin(map->map, *line);
		map->map = ft_strjoin(map->map, "\n");
		i++;
	}
	close(fd);
	return (map);
}
