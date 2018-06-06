/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:41:30 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 15:56:07 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*LoadMap(char *file, t_map *map)
{
	int		fd;
	char	**line;

	line = ft_memalloc(sizeof(char **) * 1024);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, line))
	{
		ft_putendl("Loading");
	}
	close(fd);
	return (map);
}
