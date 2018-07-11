/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:03:31 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 15:03:32 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char    *load_file(char *f)
{
    int     fd;
    char    *line;
    char    *save;
    char    *temp;

    fd = open(f, O_RDONLY);
    if (fd < 2)
        exit(1);
    while (get_next_line(fd, &line))
    {
        temp = line;
        ft_strjoin(save, line);
        free(line);
    }
    if (line)
        free(line);
    return (save);
}