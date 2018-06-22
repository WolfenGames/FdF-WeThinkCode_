/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:50:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/08 12:08:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_W 1920
# define MAX_H 1080
# define DEF_W 400
# define DEF_H 400

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
# define NUM_8			91
# define NUM_2			84
# define NUM_4			86
# define NUM_6			88

# define DEF_ANGLE		45
# define MAX_SCALE		50

# define C_BLUE			0x0000ff
# define C_GREEN		0x00ff00
# define C_RED			0xff0000

# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
	int				col;
}					t_points;
typedef struct		s_map
{
	void			*window;
	void			*mlx;
	t_points		**points;
	t_points		**og_points;
	char			**map;
	float			map_y;
	float			map_x;
	float			map_z;
	float			move_x;
	float			move_y;
	float			move_z;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	float			scale_x;
	float			scale_y;
	float			scale_z;
	float			speed;
	int				zoom;
	int				width;
	int				height;
	int				s_w;
	int				s_h;
}					t_map;

void				center(t_map *map);
void				draw_map(t_map *map);
void				display(t_map map);
void				escape(void);
void				free_points(t_map map);
void				map_init(t_map *map);
void				mapify(t_map *map, t_points ***poofy);
void				rot_x(float angle, t_map *map);
void				rot_y(float angle, t_map *map);
void				rot_z(float angle, t_map *map);
void				scale_map_down(t_map *map);
void				scale_map_up(t_map *map);
void				translate(t_map *map);
void				window_new(int keycode, t_map *map);

int					keyhook(int keycode, t_map *map);

t_points			new_point(int x, int y, int z);

t_map				load_map(int ac, char **argv, t_map *map);
t_map				get_map(t_map *map);
t_map				load_file(int fd, t_map *map);
t_map				*map_init_return(t_map *map);

#endif