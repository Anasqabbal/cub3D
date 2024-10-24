/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:01:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/18 12:01:36 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
        if ((x0 < 0 || y0 < 0 || x0 >= (int)exec->info.win_wid  || y0 >= (int)exec->info.win_hei) ||  (x0 == x1 && y0 == y1))
            break;
        mlx_put_pixel(exec->wind_image, x0, y0, 0x00000000);
    }
}