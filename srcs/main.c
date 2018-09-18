/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:43:47 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 14:43:48 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac > 2)
			ft_putendl("I can only devour one file at the moment, Thank you!");
		if (ft_strequ(ft_strrchr(av[1], '.'), ".fdf") == 0)
		{
			ft_putendl(ESCAPE_YODA);
			exit(3);
		}
		window_init(av[1]);
	}
	else
		ft_putendl("FEED ME FILES!!!!");
	return (0);
}
