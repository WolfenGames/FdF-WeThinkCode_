/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:36:11 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 11:31:32 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		getlc(char *filename)
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

static int		all_lines_equal(t_map map, int curr)
{
	int		j;
	int		i;
	int		l;

	i = 0;
	j = 0;
	l = ft_strlen(map.map[0]);
	while (map.map[i] && i < curr)
	{
		j = ((int)ft_strlen(map.map[i]) == l) ? 1 : 0;
		if (j == 0)
			break ;
		i++;
	}
	return (j);
}

void			exit_read_map(t_map file, int cur)
{
	if (!all_lines_equal(file, cur))
	{
		ft_putendl("File is invalid");
		exit(-1);
	}
}

t_map			read_map(char *filename)
{
	char	*line;
	int		fd;
	int		i;
	t_map	file;

	i = 0;
	if (!(fd = open(filename, O_RDONLY)))
		ft_putendl("Hmmm... Retard you are");
	file.height = getlc(filename);
	file.map = (char **)malloc(sizeof(char *) * file.height);
	ft_putendl_c("Siphoning file for validity :: ", filename);
	while (i < file.height)
	{
		get_next_line(fd, &line);
		ft_putendl_c("Loading Data :: ", line);
		file.map[i++] = line;
		if (i > 1)
			exit_read_map(file, i);
	}
	close(fd);
	ft_putendl_c("Finished reading :: ", filename);
	return (file);
}

t_map			load_map(int ac, char **argv, t_map *map)
{
	t_map	tmp;

	tmp = *map;
	if (ac == 2)
	{
		ft_putendl_c("Loading file :: ", argv[1]);
		if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".fdf"))
			tmp = read_map(argv[1]);
		else
		{
			ft_putendl_c("File extension is invalid :: ", argv[1]);
			exit(-1);
		}
	}
	else
	{
		ft_putendl_c("File name is invalid :( :: ", argv[1]);
		exit(-1);
	}
	map = &tmp;
	return (*map);
}
