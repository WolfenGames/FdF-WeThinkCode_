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
int         count(char *s)
{
    int     i;
    int     c;

    i = 0;
    c = 0;
    while (s[i] != '\0')
    {
        if (ft_isdigit(s[i]))
        {
            c++;
            while (ft_isdigit(s[i] && s[i]))
                i++;
        }
        i++;
    }
    return (c);
    
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
        if (i % 10 == 0)
            ft_putendl("Saving and reading, dont panick, have a smoke.");
    }
    file.w = count(file.m[0]);
    if (file.h <= 1 && file.w <= 1)
        exit(4);
    close(fd);
    return (file);
}