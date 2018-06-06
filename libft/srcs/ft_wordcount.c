/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:52:31 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/28 09:31:54 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *s, char c)
{
	int		count;
	int		words;

	count = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[count] == c)
		count++;
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			while (s[count] == c)
				count++;
			words++;
		}
		count++;
	}
	return (words);
}
