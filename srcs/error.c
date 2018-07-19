/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:11:11 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/19 08:11:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int         ft_isvalid(const char *s)
{
    char    *find;
    char    *hold;
    int     i;
    int     j;

    i = 0;
    find = ft_strchr(s, ',');
    hold = find + 1;
    while (hold[i] != '\0')
        j += (ft_ishex(hold[i++])) ? 0 : 1;
    return (j);
}

void        error_load(t_map *m)
{
    int     i;
    int     j;
    char    **sp;

    j = 0;
    i = 0;
    while (i < m->h - 1)
    {
        if (count(m->m[0]) != count(m->m[i]))
            exit(9);
        j = 0;
        sp = ft_strsplit(m->m[i], ' ');
        while (j < m->w)
        {
            if (!ft_isvalid(sp[j]))
                exit(10);
            free(sp[j]);
            j++;
        }
        free(sp);
        i++;
    }
}
