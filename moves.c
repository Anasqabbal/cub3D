/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/04 18:12:13 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


double fixing_fichbowl(double ds, double angle, t_exec *exec)
{
    // printf("the distance that your ray travels is %f and the new one is %d\n,", ds, ft_abs((int)(ds * cos(angle - exec->tex.ply.rotangle))));
    return (ft_abs((ds * cos(exec->tex.ply.rotangle - angle))));
}

void draw_the_walls22(int rx, t_exec *exec, double angle, double ds)
{
    double nheigh;
    static int n;
    int y ;
    int x ;
    int color;

    (void) angle;
    ds = fixing_fichbowl(ds, angle, exec);
    nheigh  = ((PIXELS) / ds) * ((exec->mlxx.win_wid / 5) / tan(degree_to_rad(AOV / 2))); /* the new heigh of the wall that you want to draw */
    if (isinf(nheigh))
        nheigh = n;
    n = nheigh;
    y = 0;
    x = 0;
    int clg = ((exec->mlxx.win_hei) / 2) - (nheigh / 2);
    color = 0xFF0000FF;
    while(y < clg)
        mlx_put_pixel(exec->wind_image, rx, y++,exec->inf.clg_cl);
    // if ((int)rad_to_degree (angle) > (int)45 && (int)rad_to_degree (angle) <= (int)135)
    // else if (rad_to_degree (angle) > 135 && rad_to_degree (angle) <= 225)
    //    color = 0xFF0000;
    // else if (angle > degree_to_rad(225) && angle <= degree_to_rad(315))
    //     color = 0xFF0000;
    // else if (angle > degree_to_rad(315) && angle <= degree_to_rad(45))
    //    color = 0xFF0000;
    while((int)x++ < nheigh)
        mlx_put_pixel(exec->wind_image, rx, y++, color);
    while(y < (int)exec->mlxx.win_hei)
        mlx_put_pixel(exec->wind_image, rx, y++, exec->inf.flr_cl);
    (void)exec;
}

// int trace_rays1(t_exec *exec)
// {
//     double start_angle;
//     double x;
//     double y;
//     double i = 1;
//     double angle_;
//     int cc = 0;
//     // int hr_inter;

//     angle_ = degree_to_rad((AOV / 2));
//         x  = exec->tex.ply.px;
//         double inc = exec->tex.ply.inc;
//         y = (exec->tex.ply.py / (PIXELS))  * PIXELS;
//         x -=  (exec->tex.ply.py - y) / tan(exec->tex.ply.rotangle);

//         // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (int)x, (int)y, 0x000000); // the same
//     while((int)i < 2)
//     {
//         /* horizental increment */
//         start_angle = (exec->tex.ply.rotangle - (angle_ - (i * (M_PI / 180))));
//         y = (exec->tex.ply.py / (PIXELS))  * PIXELS;
//         x = exec->tex.ply.px - ((exec->tex.ply.py - y) / tan(start_angle));
//         int xinc = (exec->tex.ply.py - y)  / tan(start_angle);
//         while(x && y &&  x >  0 && y > 0 && x < exec->mlx.win_wid && y < exec->mlx.win_hei && exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
//         {
//             if (exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
//                 mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (int)x, (int)y, 0x000000);
//             else
//                 break ;
//             y -= PIXELS;
//             x -= xinc;
//             printf("(%d, %d)\n", (int)y, (int)x);
//         }
//         /* vertical increment */
//         x = (exec->tex.ply.px / (PIXELS))  * PIXELS;
//         y = exec->tex.ply.py - (exec->tex.ply.px - x) * tan((start_angle));
//         xinc = (exec->tex.ply.px - x) * tan((start_angle));
//         while(x && y &&  x >  0 && y > 0  && x < exec->mlx.win_wid && y < exec->mlx.win_hei && exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
//         {
//             if (exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
//                 mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (int)x, (int)y, 0xC60404);
//             else
//                 break ;
//             y -= xinc;
//             x -= PIXELS;
//             printf("(%d, %d)\n", (int)y, (int)x);
//         }
//         i += inc;
//     }
//         // draw_the_walls11(cc++, y, exec, start_angle, i); // to destroy 3d map
//     (void)cc;
//     return (0);
// }

int ft_check_walls(t_exec *exec, int ind)
{
    int i;
    int y;
    int x;
    int j;

    i = 1;
    j = 0;
    while(i < SPEED)
    {
        if (ind == 1)
        {
            if (j++ == 0)
                y = ((exec->tex.ply.py / PIXELS) * PIXELS ) + PIXELS;
            y =  exec->tex.ply.py + (sin(exec->tex.ply.rotangle) * i);
            if (exec->tex.ply.rotangle > degree_to_rad(90))
                x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle) * i);
            else
                x = exec->tex.ply.px + (cos(exec->tex.ply.rotangle) * i);
            if (exec->inf.map[y / PIXELS][x / PIXELS] == '1')
                return (0);
            
        }
        else
        {
            if (j++ == 0)
            {
                 y = (exec->tex.ply.py / PIXELS) * PIXELS ;
                if (exec->tex.ply.rotangle >= degree_to_rad(90) && exec->tex.ply.rotangle <= degree_to_rad(270))
                    x = exec->tex.ply.px + (cos(exec->tex.ply.rotangle) * exec->tex.ply.rds);
                else
                    x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle) * exec->tex.ply.rds);
            }
            draw_map(exec);
            mlx_put_pixel(exec->wind_image, exec->tex.ply.px , y, 0x5AFF055A);
            /*check up move*/
            if (exec->tex.ply.rotangle >= degree_to_rad(90) && exec->tex.ply.rotangle <= degree_to_rad(270))
                x += (cos(exec->tex.ply.rotangle) * i);
            else
                x -= (cos(exec->tex.ply.rotangle) * i);
            if (exec->inf.map[y / PIXELS][x / PIXELS] == '1')
            {
                if (i == 1)
                    return (0);
                else
                    return (printf("the value OFOF i == %d\n", i), i);
            }
            printf("the value of i == %d\n", i);
        }
        i++;
    }
    return (i);
}

int     move_up(t_exec *exec)
{
    if (!ft_check_walls(exec, 0))
        return (0);
    exec->tex.ply.py -= (sin(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    exec->tex.ply.px -= (cos(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    return (0);
}

int move_down(t_exec *exec)
{
    if (!ft_check_walls(exec, 1))
        return (0);
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    return (0);
}



int move_righ(t_exec *exec)
{
    if (!ft_check_walls(exec, 0))
        return (0);
    exec->tex.ply.rotangle += VIEW_SPEED;
    if (exec->tex.ply.rotangle > (M_PI * 2))
        exec->tex.ply.rotangle -= 2 * M_PI;
    return (0);
}



int move_left(t_exec *exec)
{
    exec->tex.ply.rotangle -= VIEW_SPEED;
    if (exec->tex.ply.rotangle < 0)
        exec->tex.ply.rotangle += 2 * M_PI;
     return (0);
}

void catch_moves(mlx_key_data_t key, void *p)
{
    t_exec *exec;

    exec = p;
    if (key.key == MLX_KEY_RIGHT)
        move_righ(exec);
    else if (key.key == MLX_KEY_LEFT)
        move_left(exec);
    else if (key.key == MLX_KEY_UP)
        move_up(exec);
    else if (key.key == MLX_KEY_DOWN)
        move_down(exec);
    ft_move_player(exec);// to destroy 2d map
    ray_casting(exec);
    // trace_rays1(exec);
}