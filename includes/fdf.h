/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:50:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 10:42:34 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_W 1920
# define MAX_H 1080
# define DEF_W 1600
# define DEF_H 900

# define A 				0
# define S 				1
# define D 				2
# define W 				13
# define ARROW_UP 		126
# define ARROW_DOWN		125
# define ARROW_RIGHT	124
# define ARROW_LEFT 	123
# define PG_UP 			116
# define PG_DOWN		121
# define ESC			53
# define NUM_PLUS		69
# define NUM_MINUS		78
# define NUM_1			83
# define NUM_3			85
# define NUM_2			84
# define NUM_4			86
# define NUM_6			88
# define NUM_7			89
# define NUM_9			92
# define NUM_8			91

# define DEF_ANGLE		15
# define MAX_SCALE		50
# define MS				map->scale
# define MP				map->points

# define ESCAPE_YODA	"Hmmm... Fucked up you did"

# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
	int				c;
	t_bool			m;
}					t_points;
typedef struct		s_winfo
{
	float			c_w;
	float			c_h;
	char			*wn;
}					t_winfo;
typedef struct		s_map
{
	void			*win;
	void			*mlx;
	void			*img;
	void			*dat;
	char			**m;
	int				bpp;
	int				sl;
	int				endn;
	int				m_y;
	int				m_x;
	int				m_z;
	int				mv_x;
	int				mv_y;
	int				mv_z;
	int				w;
	int				h;
	int				pix;
	float			r_x;
	float			r_y;
	float			r_z;
	float			scl;
	t_points		**pnts;
	t_winfo			wi;
}					t_map;

t_map				*window_init(char *m_n);

t_map				load_file(char *f, t_map *m);

int					keyhook(int keycode, t_map *m);
int					buttonhook(int button, t_map *m);

int					draw(t_map *m);

#endif
