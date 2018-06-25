#include "../includes/fdf.h"

int     keyhook(int keycode, t_map *map)
{
  
    if (keycode == 53)
    {
        mlx_destroy_window(map->mlx, map->win);
        exit(0);
    }
    return (0);
}

int     expose_hook(t_map *map)
{
    ft_putendl(map->mlx);
}

int     main(void)
{
    t_map   *map;
    
    map = malloc(sizeof(t_map));
    map->mlx = mlx_init();
    map->w = WIN_W;
    map->h = WIN_H;
    map->win = mlx_new_window(map->mlx, map->w, map->h, "FUCKERY");
    mlx_key_hook(map->win, keyhook, map);
    mlx_expose_hook(map->win, expose_hook, map);
    mlx_loop(map->mlx);
    return (0);
}