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
# define NUM_5			87
# define NUM_6			88
# define NUM_7			89
# define NUM_9			92
# define NUM_8			91

# define ESCAPE_YODA	"Hmmm... Fucked up you did"
# define LE_OF(A, B) 	(A < B ? A : B)

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
	int				c;
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
	void			**img;
	void			*dat;
	char			**m;
	int				bpp;
	int				sl;
	int				endn;
	int				m_y;
	int				m_x;
	float			mv_x;
	float			mv_y;
	int				w;
	int				h;
	float			r_x;
	float			r_y;
	float			r_z;
	float			scl;
	t_points		**pnts;
	t_winfo			wi;
}					t_map;

void				load_file(char *f, t_map *m);

t_points			new_point(int x, char *y, int z, t_map *m);

void				mapify(t_map *m, t_points ***p);
void				rotate(t_map *m);
void				error_load(t_map *m);
void				rot_x(float angle, t_map *map);
void				rot_y(float angle, t_map *map);
void				rot_z(float angle, t_map *map);
void				window_init(char *m_n);

int					count(const char *s);
int					draw(t_map *m);
int					key_press_hook(int keycode, t_map *m);
int					exit_hook(int keycode, t_map *m);
#endif
