/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:08:04 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 07:53:25 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_setreturn(int num, size_t b, t_bool neg)
{
	if (b > 18 && neg)
		return (0);
	if (b > 18)
		return (-1);
	if (neg)
		return (-num);
	return (num);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	t_bool	neg;
	size_t	b;

	b = 0;
	i = 0;
	num = 0;
	neg = FALSE;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f' || str[i] == '0')
		i++;
	neg = (str[i] == '-') ? TRUE : FALSE;
	if ((str[i - 1] && str[i - 1] == '0') && (str[i] == '-' || str[i] == '+'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		b++;
		num *= 10;
		num += (str[i] - 48);
		i++;
	}
	return (ft_setreturn(num, b, neg));
}
