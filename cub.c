/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/07 14:53:22 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void bresenham_line_algo2(int y0, int x0, int y1, int x1, t_exec *exec)
 {
    int dx;
    int dy;
    int sx ;
    int sy ;
    int err;
    int e2;

    dx = ft_abs(x1 - x0);
    dy = ft_abs(y1 - y0);
    if (x0 < x1)
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;
    mlx_put_pixel(exec->wind_image, x0, y0, 0x12FF0012);
    while (1)
    {
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
         {
            err += dx;
            y0 += sy; 
        }
        if ((x0 < 0 || y0 < 0 || x0 >= (int)exec->mlxx.win_wid  || y0 >= (int)exec->mlxx.win_hei) ||  (x0 == x1 && y0 == y1))
            break;
        mlx_put_pixel(exec->wind_image, x0, y0, 0x00000000);
    }
}

// int ft_dda_algo(t_exec *exec, double endy, double endx)
// {
//     double m;
//     double starty;
//     double startx;

//     starty = exec->tex.ply.py;
//     startx = exec->tex.ply.px;
//     m = (endy - starty) / (endx - startx);
//     int i = 1;
//     while(i < 30)
//     {
//         printf("(y == %d x == %f)\n", (int)starty, startx);
//         if (m < 1)
//         {
//             startx += 1;
//             starty += m;
//         }
//         else if (m > (double)1)
//         {
//             startx += 1;
//             starty += (1 / m);
//         }
//         else
//         {
//             startx += 1;
//             starty += 1;
//         }
//         mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, startx, starty, 0x000000);
//         i++;
//     }
//     return (0);
// }

// void ft_draw_rays(t_exec *exec)
// {
//     exec->line.x = exec->tex.ply.px + (cos(exec->tex.ply.rotangle) * SPEED);
//     exec->line.y = exec->tex.ply.py + (sin(exec->tex.ply.rotangle) * SPEED);
//     mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, exec->line.x, exec->line.y, 0x000000);
//     printf("TRGET (%d, %d)\n",  exec->line.y,  exec->line.x);
//     ft_dda_algo(exec, exec->line.y,  exec->line.y);
// }

int start_cub(char **av)
{
    t_exec exec;

    if (init_structs(&exec, 0, av) < 0)
        return (-1);
    if (creat_and_start_awindow(&exec) < 0)
        return (-1);
    // mlx_destroy_window(exec.mlx.mlx, exec.mlx.mlx_w); //TODO to destory 2d map uncomment this destroy
    // mlx_destroy_window(exec.mlx.mlx, exec.mlx.mlx_w1); //TODO to destory 3d map uncomment this destroy
    draw_map(&exec);       // the same
    set_player_info(&exec);
    ray_casting(&exec);
    mlx_key_hook(exec.mlx, &catch_moves, &exec);
    mlx_loop(exec.mlx);
    // mlx_hook(exec.mlx.mlx_w1, 2, 0, catch_moves, &exec); // switch the window pointer for which window you want to catch keys
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (ft_putstr_fd("invalide argument\n", 2), 1);
    if (start_cub(av) < 0)
        return (1);
    // mlx_put_pixel()
}