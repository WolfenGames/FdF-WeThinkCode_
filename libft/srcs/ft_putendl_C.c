/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_C.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:14:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 07:30:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_C(char *dest, char *str)
{
	if (dest && str)
		ft_putendl(ft_strjoin(dest, str));
	else if (!str)
		ft_putendl(ft_strjoin(dest, "No filename passed"));
}
