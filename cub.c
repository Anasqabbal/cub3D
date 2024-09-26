/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/26 15:24:18 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void bresenhams_line_algo(t_exec *exec, int endy, int endx)
{
    int subx;
    int suby;
    int m;
    int x;
    int y;

    /* starting point x = 330 y == 150*/
    /* end point x == 330 y == 120 */
    /* x represente horizental line and y represente vertical line */
    subx = endx - exec->tex.ply.px;
    suby = endy - exec->tex.ply.py;
    x = exec->tex.ply.px;
    y = exec->tex.ply.py;

    m = (2 * suby) - subx;
    mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, endx, endy, 0xEFFF00);
    printf("enter\n");
    if (subx == 0)
    {
        while (y <= endy)
        {
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x, y, 0x000000);
            y++;  // Increment y only
        }
        while (y > endy)
        {
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x, y, 0x000000);
            y--;
        }
    }
    else if (suby == 0)
    {
         while (x <= endx)
        {
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x, y, 0x000000);
            y++;  // Increment y only
        }
        while (x > endx)
        {
        
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x, y, 0x000000);
            x--;
        }
    }
    else
    {
        int i = -1;
        while (i++ < 30)
        {
            if (m < 0)
                m += (2 * suby);
            else
            {
                m +=  + (2 * suby) - (2 * subx);
                y = y + 1;
            }
            x = x + 1;
            printf("the vlaue x == %d\n", x);
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x, y, 0x000000);
        }
    }
    printf("gone\n");
}

void plot(int x, int y) {
    printf("Plotting pixel at (%d, %d)\n", x, y);
}

int ft_abs(int nm)
{
    if (nm < 0)
        return (nm *= -1);
    else
        return (nm);
}

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
    // printf("y0 %d x0 %d === %c\n", (y0 - (PIXELS / 2)) / PIXELS, (x0 - (PIXELS / 2)) / PIXELS);
    while (1)
    {
        if ((x0 == x1 && y0 == y1))
            break;
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
        mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x0, y0, 0x000000);
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
    creat_and_start_awindow(&exec.mlx);
    draw_the_floor(&exec);
    draw_the_walls(&exec);
    draw_map(&exec);
    draw_the_player(&exec);
    mlx_hook(exec.mlx.mlx_w, 2, 0, catch_moves, &exec);
    // mlx_key_hook(exec.mlx.mlx_w, catch_moves, &exec);
    mlx_loop(exec.mlx.mlx);
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (ft_putstr_fd("invalide argument\n", 2), 1);
    if (start_cub(av) < 0)
        return (1);
}