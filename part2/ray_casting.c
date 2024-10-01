/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/01 16:49:13 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int find_horizontal_inter(int   i, double angle,t_exec *exec)
{
    double cur_psx;   
    double cur_psy;
    (void)i;

    cur_psy = (exec->tex.ply.py / PIXELS) * PIXELS;
    cur_psx = exec->tex.ply.px - ((exec->tex.ply.py - cur_psy) / tan(angle));
    int c = 0;
    while(   exec->inf.map[(int)(cur_psy / PIXELS)][(int)(cur_psx / PIXELS)] != '1' && c < 3)
    {
        mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, cur_psx, cur_psy, 0x026F00);
        cur_psy -= PIXELS;
        cur_psx -= (PIXELS) / tan(angle);
        printf("he %d %d\n", (int)cur_psx, (int)cur_psy);
        c++;
    }
    return (0);
}

int ray_casting(t_exec *exec)
{
    double angle;
    double i = 0;
    double inc;

    inc = exec->tex.ply.inc;
    (void)i;
    (void)angle;
    // printf("your exec->tex.ply.rotangle == %d\n", (int)rad_to_degree(exec->tex.ply.rotangle));
    int c = 0;
    while((int)i < (AOV))
    {
        angle = exec->tex.ply.rotangle - degree_to_rad((AOV / 2) + i);
        find_horizontal_inter(i, angle, exec);
        /* find horizental intersections */
        i += inc;
        c++;
    }
    return (0);
}