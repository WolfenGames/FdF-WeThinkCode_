/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:24:13 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:40:34 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t		i;
	size_t		j;

	if (!*needle)
		return ((char *)hay);
	i = 0;
	while (hay[i] != '\0' && i < n)
	{
		j = 0;
		while (hay[i + j] && i + j < n && needle[i] && hay[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
