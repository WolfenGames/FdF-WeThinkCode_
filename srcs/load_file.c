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
            while (ft_isdigit(s[i]) && s[i])
                i++;
        }
        else
            i++;
    }
    return (c);
    
}

void        load_file_error(const char  *dat, const int i)
{
    if (ft_strlen(dat) == 0 ||
        (dat[i] == ' ' && dat[i + 1] == ' '))
    {
        ft_putendl(dat);
        exit(8);
    }
}

void        load_file(char *f, t_map *m)
{
    char    *dat;
    int     fd;
    int     i;

    i = 0;
    if (!(fd = open(f, O_RDONLY)))
    {
        ft_putendl(ESCAPE_YODA);
        exit(3);
    }
    m->h = get_lc(f);
    m->m = (char **)malloc(sizeof(char *) * m->h);
    while (i < m->h)
    {
        get_next_line(fd, &dat);
//        load_file_error(dat, i);
        m->m[i++] = dat;
        dat = NULL;
    }
    close(fd);
    m->w = count(m->m[0]);
    if (m->h < 1 && m->w < 1)
        exit(4);
    if (count(m->m[0]) != count(m->m[1]))
        exit(5);
}