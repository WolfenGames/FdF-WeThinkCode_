/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:36:11 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/07 15:38:17 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		getlc(char	*filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putendl("Fucked up you did");
		exit(-1);
	}
	while (get_next_line(fd, &line))
	{
		lines++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (lines);
}

int			allLinesEqual(t_map map)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = ft_strlen(map.map[0]);
	while (map.map[i] && i < map.height)
	{
		j = ((int)ft_strlen(map.map[i]) == l) ? 1 : 0;
		if (j == 0)
			break ;
		i++;
	}
	return (j);
}

t_map			readmap(char *filename)
{
	char	*line;
	int		fd;
	int		i;
	t_map	file;

	i = 0;
	file.height = 0;
	file.map = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		return (file);
	file.height = getlc(filename);
	file.map = (char **)malloc(sizeof(char *) * file.height);
	while (i < file.height)
	{
		get_next_line(fd, &line);
		file.map[i++] = line;
	}
	close(fd);
	if (!allLinesEqual(file))
	{
		ft_putendl("File is invalid");
		exit(-1);
	}
	file.scale = 5;
	file.width = (int)ft_strlen(file.map[0]);
	return (file);
}

t_map			loadMap(int ac, char **argv, t_map *map)
{
	t_map	tmp;

	tmp = *map;
	if (ac == 2)
	{
		tmp = readmap(argv[1]);
	}
	map = &tmp;
	return (*map);
}
