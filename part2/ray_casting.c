/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/02 17:36:04 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double find_horizontal_inter(double angle,t_exec *exec)
{
    double cur_psx;   
    double cur_psy;
    double set_incx;
    int     b;

    /* adjust angle */
    set_incx = PIXELS / tan(angle);
    if (angle > degree_to_rad(0) && angle < degree_to_rad(180))
    {
        cur_psy = (exec->tex.ply.py / PIXELS) * PIXELS;
        b = -1;
    }
    else
    {
        b = 1;
        cur_psy = ((exec->tex.ply.py / PIXELS) * PIXELS) + PIXELS;

    }
    cur_psx = exec->tex.ply.px - ((exec->tex.ply.py - cur_psy) / tan(angle));
    // if (cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlx.win_wid && cur_psy < exec->mlx.win_hei &&  exec->inf.map[(int)((cur_psy + b)/ PIXELS)][(int)(cur_psx / PIXELS)] != '1')
    // {
        while(cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlx.win_wid && cur_psy < exec->mlx.win_hei &&  exec->inf.map[(int)((cur_psy + b)/ PIXELS)][(int)(cur_psx / PIXELS)] != '1')
        {
            /* adjust angle */
            if (angle > degree_to_rad(0) && angle < degree_to_rad(180))
            {
                cur_psy -= PIXELS;
                cur_psx -= set_incx;
            }
            else
            {
                cur_psy += PIXELS;
                cur_psx += set_incx;
            }
        }
        // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, cur_psx, cur_psy, 0x026F00);
    // }
    double ah = (cur_psy - exec->tex.ply.py) / cos((degree_to_rad(90) - angle));
    return (ft_abs(ah));
}

int find_vertical_inter(double angle, t_exec *exec)
{
    double cur_psx;   
    double cur_psy;
    double set_incy;
    int     b;

    set_incy = PIXELS * tan(angle);
    if (angle > degree_to_rad(90) && angle < degree_to_rad(270))
    {
        b = 1;
        cur_psx = ((exec->tex.ply.px / PIXELS) * PIXELS) + PIXELS;
    }
    else
    {
        b = -1;
        cur_psx = (exec->tex.ply.px / PIXELS) * PIXELS;
    }
    cur_psy = exec->tex.ply.py - ((exec->tex.ply.px - cur_psx) * tan(angle));
    // if (cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlx.win_wid && cur_psy < exec->mlx.win_hei &&  exec->inf.map[(int)(cur_psy / PIXELS)][(int)((cur_psx + b) / PIXELS)] != '1')
    // {
        while(cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlx.win_wid && cur_psy < exec->mlx.win_hei &&  exec->inf.map[(int)((cur_psy) / PIXELS)][(int)((cur_psx + b) / PIXELS)] != '1')
        {
            if (angle > degree_to_rad(90) && angle < degree_to_rad(270))
            {
                cur_psx += PIXELS;
                cur_psy += set_incy;
            }
            else
            {
                cur_psx -= PIXELS;
                cur_psy -= set_incy;
            }
        // }
    }
    // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, cur_psx, cur_psy, 0xFF2222);
    double ah = (cur_psy - exec->tex.ply.py) / cos( (degree_to_rad(90) - angle));
    return (ft_abs(ah));
}

int ray_casting(t_exec *exec)
{
    double angle;
    double i ;
    double inc;
    double dsh;
    double dsv;

    inc = exec->tex.ply.inc;
    int c = 0;
    i = 0;
    while((int)i <= (AOV))
    {
        angle = exec->tex.ply.rotangle - (degree_to_rad((AOV / 2) - i));
        if (angle > degree_to_rad(360))
            angle -= (2 * M_PI);
        dsh = find_horizontal_inter(angle, exec);
        dsv = find_vertical_inter(angle, exec);
        if (dsh < dsv)
            draw_the_walls22(c, exec, angle, dsh);
        else
           draw_the_walls22(c, exec, angle, dsv);
        i += inc;
        c++;
    }
    return (0);
}
