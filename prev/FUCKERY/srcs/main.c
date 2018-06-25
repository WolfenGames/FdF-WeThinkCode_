#include "../includes/fdf.h"

int     keyhook(int keycode, t_map *map)
{
    if (keycode == 53)
    {
        mlx_destroy_window(map->mlx, map->win);
        exit (0);
    }
    
    return (0);
}

int     expose_hook(t_map *map)
{
    int     x;
    int     y;
    int     *size_line;

    y = -1;
    size_line = (int *)malloc(sizeof(int));
    map->img = mlx_new_image(map->mlx, map->w, map->h);
    map->data = mlx_get_data_addr(map->img, &map->bpp, size_line, &map->endian);
    mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
    return (0);
}

int     close_hook(int button, t_map *map)
{
    (void)map;
    (void)button;
    exit(0);
    return (0);
}

int     main(void)
{
    t_map   *map;
    
    map = malloc(sizeof(t_map));
    map->bpp = 100;
    map->endian = 12;
    map->mlx = mlx_init();
    map->w = WIN_W;
    map->h = WIN_H;
    map->win = mlx_new_window(map->mlx, map->w, map->h, "FUCKERY");
    mlx_expose_hook(map->win, expose_hook, map);
    mlx_hook(map->win, 17, 0, close_hook, map);
    mlx_hook(map->win, 2, 0, keyhook, map);
    mlx_loop(map->mlx);
    return (0);
}