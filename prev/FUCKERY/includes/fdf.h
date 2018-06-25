#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>

# define WIN_W 500
# define WIN_H 500   

typedef struct  s_map
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *data;
    int         bpp;
    int         endian;
    int         w;
    int         h;
}               t_map;

#endif