/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:29:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 11:33:46 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				main(int ac, char **argv)
{
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_putendl("Welcome to the Jungle");
	//*map = load_map(ac, argv, map);
	//mapify(map, &map->points);
	map_init(map);
	return (0);
}