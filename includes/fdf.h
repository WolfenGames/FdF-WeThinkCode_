/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:50:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/06 16:47:57 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_W 1920
# define MAX_H 1080
# define DEF_W 640 
# define DEF_H 480

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

# define BLUE 			0x0000ff
# define GREEN			0x00ff00
# define RED			0xff0000

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
	char			**map;
	t_point			*points;
	t_pos			pos;
	t_zoom			*zoom;
	t_scale			*scale;
}					t_map;
typedef struct		s_win
{
	void	*window;
	void	*mlx;
}					t_win;

void				*DrawWindow(t_win *win);
void				*LoadMap(char *file, t_map *map);
void				*DrawMap(t_win *win);

void				HandleInput(t_win *win, t_map *map);

int					handleExit(int keycode);
int					moveCamera(int keycode, t_map *map);
int					rotCamera(int keycode, t_map *map);
int					scaleMap(int keycode, t_map *map);
int					zoomMap(int keycode, t_map *map);

t_map				*newMap(t_map *map);

#endif
