/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/08 18:00:12 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_abs(int nm)
{
    if (nm < 0)
        return (nm *= -1);
    else
        return (nm);
}

int find_horizontal_inter(double angle,t_exec *exec, t_ray *ray)
{
    double cur_psx;   
    double cur_psy;
    double set_incx;
    int     b;

    b = 1;
    set_incx = PIXELS / tan(angle);
    if (angle > degree_to_rad(0) && angle < degree_to_rad(180))
    {
        cur_psy = ((int)exec->tex.ply.py / PIXELS) * PIXELS;
        b = -1;
    }
    else
        cur_psy = (((int)exec->tex.ply.py / PIXELS) * PIXELS) + PIXELS;

    cur_psx = (int)exec->tex.ply.px - (((int)exec->tex.ply.py - cur_psy) / tan(angle));
    // int c = 0;
    while(cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy > 0 && cur_psy < exec->mlxx.win_hei)
    {
        mlx_put_pixel(exec->wind_image, (int)cur_psx, (int)cur_psy, 0xFF0505FF);
        if (cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy > 0 && cur_psy < exec->mlxx.win_hei && exec->inf.map[(int)floor(((cur_psy + b)/ PIXELS))][(int)floor(((cur_psx) / PIXELS))] == '1')
            break ; 
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
    // if (cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy < exec->mlxx.win_hei)
    //     mlx_put_pixel(exec->wind_image, (int)cur_psx, (int)cur_psy, 0xFF0505FF);
    double ah = (cur_psy - (int)exec->tex.ply.py) / cos((degree_to_rad(90) - angle));
    ah = ft_abs(ah);
    ray->ds = ah;
    ray->dx = ((int)exec->tex.ply.px) - (cos(angle) * (int)ah) ;
    ray->dy =  ((int)exec->tex.ply.py) - (sin(angle) * (int)ah);
    // printf("dsH == %f\n", ah);
    return (ft_abs(ah));
}

int find_vertical_inter(double angle, t_exec *exec, t_ray *ray)
{
    double ah;
    double cur_psx;   
    double cur_psy;
    double set_incy;
    int     b;

    b = 0;
    // mlx_put_pixel(exec->wind_image, exec->tex.ply.px, exec->tex.ply.py, 0xB30000BB);
    set_incy = PIXELS * tan(angle);
    if (angle >= degree_to_rad(90) && angle <= degree_to_rad(270))
        cur_psx = (((int)exec->tex.ply.px / PIXELS) * PIXELS) + PIXELS;
    else
    {
        b = -1;
        cur_psx = ((int)exec->tex.ply.px / PIXELS) * PIXELS;
    }
    cur_psy = (int)exec->tex.ply.py - (((int)exec->tex.ply.px - cur_psx) * tan(angle));
    // int c = 0;
    // mlx_put_pixel(exec->wind_image, (int)cur_psx, (int)exec->tex.ply.py, 0xFF1600FF);
    while(cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy < exec->mlxx.win_hei &&  exec->inf.map[(int)((cur_psy) / PIXELS)][(int)((cur_psx + b) / PIXELS)] != '1')
    {
        // mlx_put_pixel(exec->wind_image, (int)cur_psx, (int)cur_psy, 0xFF0505FF);
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
    }
    // if (cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy < exec->mlxx.win_hei)
    //     mlx_put_pixel(exec->wind_image, (int)cur_psx, (int)cur_psy, 0xFF0505FF);
    ah = (cur_psy - (int)exec->tex.ply.py) / cos( (degree_to_rad(90) - angle));
    ah = ft_abs(ah);
    ray->ds = ah;
    ray->dx = ((int)exec->tex.ply.px) - (cos(angle) * (int)ah) ;
    ray->dy =  ((int)exec->tex.ply.py) - (sin(angle) * (int)ah);
    return (ah);
}

int ray_casting(t_exec *exec)
{
    double  angle;
    double  i ;
    double  inc;
    double  dsh;
    double  dsv;
    t_ray   ray[2];
    int     c;

    inc = exec->tex.ply.inc;
    c = 0;
    i = 0;
    (void)dsh;
    (void)dsv;
    while((int)i < 1)
    {
        angle = exec->tex.ply.rotangle - (degree_to_rad((AOV / 2) - i));
        if (angle > degree_to_rad(360))
            angle -= (2 * M_PI);
        dsh = find_horizontal_inter(angle, exec, &ray[0]);
        // dsv = find_vertical_inter(angle, exec, &ray[1]);
        // // if (((dsh < dsv) && dsh != (INT_MIN)) || dsv == (INT_MIN))
        // //     bresenham_line_algo2((int)exec->tex.ply.py, (int)exec->tex.ply.px, (int)ray[0].dy, (int)ray[0].dx, exec);
        // // else
        // //     bresenham_line_algo2((int)exec->tex.ply.py, (int)exec->tex.ply.px , (int)ray[1].dy, (int)ray[1].dx, exec);
        // if ((dsh < dsv && dsh != INT_MIN) || dsv == INT_MIN)
        //     draw_the_walls22(c, exec, angle, ray[0].ds);
        // else
        //     draw_the_walls22(c, exec, angle, ray[1].ds);
        i += inc;
        // c++;
    }
    return (0);
}
