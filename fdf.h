/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:50:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 10:09:14 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_W 1080
# define MAX_H 1920
# define DEF_W 1600
# define DEF_H 900


# include <mlx.h>
# include <math.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	void			*color;
}					t_point;
typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;
typedef struct		s_zoom
{
	int				x_zoom;
	int				y_zoom;
}					t_zoom;
typedef struct		s_scale
{
	int				x_scale;
	int				y_scale;
}					t_scale;
typedef struct		s_map
{
	char			**map;
	t_point			*points;
	t_pos			pos;
	t_zoom			zoom;
	t_scale			scale;
}					t_map;


#endif
