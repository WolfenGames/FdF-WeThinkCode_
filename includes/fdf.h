/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:50:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 12:19:58 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_W 1080
# define MAX_H 1920
# define DEF_W 1600 
# define DEF_H 900

# define A 				0
# define S 				1
# define D 				2
# define W 				13
# define UP_ARROW 		126
# define DOWN_ARROW		125
# define RIGHT_ARROW	124
# define LEFT_ARROW  	123 
# define PG_UP 			116
# define PG_DOWN		121
# define ESC			53
# define NUM_PLUS		69
# define NUM_MINUS		78
# define NUM_8			91
# define NUM_2			84
# define NUM_4			86
# define NUM_6			88

# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"

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
	void			*window;
	void			*mlx;
	char			**map;
	t_point			*points;
	t_pos			pos;
	t_zoom			zoom;
	t_scale			scale;
}					t_map;

void	*DrawWindow(void *mlx, void *window, char *title);

#endif
