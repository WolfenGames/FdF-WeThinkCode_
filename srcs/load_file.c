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

static int  get_lc(char *f)
{
    int     fd;
    int     l;
    char    *dat;

    l = 0;
    if (!(fd = open(f, O_RDONLY)))
    {
        ft_putendl(ESCAPE_YODA);
        exit(2);
    }
    while (get_next_line(fd, &dat) > 0)
    {
        l++;
        free(dat);
        dat = NULL;
    }
    if (dat)
        free(dat);
    close(fd);
    return (l);
}

t_map       load_file(char *f, t_map *m)
{
    char    *dat;
    int     fd;
    int     i;
    t_map   file;

    file = *m;
    i = 0;
    if (!(fd = open(f, O_RDONLY)))
    {
        ft_putendl(ESCAPE_YODA);
        exit(3);
    }
    file.h = get_lc(f);
    file.m = (char **)malloc(sizeof(char *) * file.h);
    while (i < file.h)
    {
        get_next_line(fd, &dat);
        file.m[i++] = dat;
        ft_putendl_c("Line :: ", dat);
    }
    file.w = ft_strlen(file.m[0]);
    close(fd);
    return (file);
}