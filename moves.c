/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/03 16:34:11 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


// void set_pixels_to_image_pro(t_img *img, int nheigh, t_exec *exec)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     int clg = ((exec->inf.hei * PIXELS) / 2) - nheigh;
//     char *image = exec->tex.image;
//         while(y < clg)
//         {
//             x = 0;
//             while(x < 4)
//                 *(int *)((image + ((y * img->line_) + (x++ * (img->bits_pp / 8))))) =  exec->inf.clg_cl;
//             y++;
//         }
// 		x = 0;
//         int yy = 0;
//         while(yy < nheigh)
//         {
//             x = 0;
//             while(x < 4)
//                 *(int *)((image + ((y * img->line_) + (x++ * (img->bits_pp / 8))))) =  0xFB001D;
//             yy++;
//             y++;
//         }
//         while(y < (int)exec->mlx.win_hei)
// 		{
//             x = 0;
//             while(x < 4)
//                 *(int *)((image + ((y * img->line_) + (x++ * (img->bits_pp / 8))))) =  exec->inf.flr_cl;
// 		    y++;
// 		}
// }

// void draw_the_walls11(int rx, double ry, t_exec *exec, double angle, int nro)
// {
//     int nheigh;
//     double  ah;
//     int n;
   

//     (void)nro;
//     (void)n;
    
//     ah = (ry - exec->tex.ply.py) / cos((degree_to_rad(90) - angle));
//     ah = abs((int)ah);
//     nheigh  = ((PIXELS) / ah) * (PIXELS * 2); /* the new heigh of the wall that you want to draw */
//     int y ;
//     int x ;
//     n = 0;
//     y = 0;
//     x = 0;
//     int clg = (exec->mlx.win_hei / 2) - (nheigh);
//     while(y < clg)
//         mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++,exec->inf.clg_cl);
//     while((int)x++ < nheigh)
//     {
//         /* draw the new wall */
//         // if (exec->tex.ply.rotangle > degree_to_rad(45) && exec->tex.ply.rotangle <= degree_to_rad(135))
//             mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, 0xFF0000);
//         // else if (exec->tex.ply.rotangle > degree_to_rad(135) && exec->tex.ply.rotangle <= degree_to_rad(225))
//         //     mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, 0xFB001D);
//         // else if (exec->tex.ply.rotangle > degree_to_rad(225) && exec->tex.ply.rotangle <= degree_to_rad(315))
//         //     mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, 0xE00606);
//         // else if (exec->tex.ply.rotangle > degree_to_rad(315) && exec->tex.ply.rotangle <= degree_to_rad(45))
//         //     mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, 0xC60404);
//     }
//     while(y < (int)exec->mlx.win_hei)
//         mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, exec->inf.flr_cl);
//     (void)ry;
//     (void)exec;
// }

void draw_the_walls22(double rx, t_exec *exec, double angle, double ah)
{
    int nheigh;
    int n;
    static int nh;
    
    (void) angle;
    nheigh  = ((PIXELS) / ah) * ((exec->mlxx.win_wid / 5) / tan(degree_to_rad(AOV / 2))); /* the new heigh of the wall that you want to draw */
    if (nheigh == 0)
        nheigh = nh;
    else
        nh = nheigh;
    int y ;
    int x ;
    n = 0;
    y = 0;
    x = 0;
    int clg = (exec->mlxx.win_hei / 2) - (nheigh / 2);
    int color;
    while(y < clg)
        mlx_put_pixel(exec->wind_image, rx + n, y++,exec->inf.clg_cl);
       color = 0xFF0000FF;
    // if ((int)rad_to_degree (angle) > (int)45 && (int)rad_to_degree (angle) <= (int)135)
    // else if (rad_to_degree (angle) > 135 && rad_to_degree (angle) <= 225)
    //    color = 0xFF0000;
    // else if (angle > degree_to_rad(225) && angle <= degree_to_rad(315))
    //     color = 0xFF0000;
    // else if (angle > degree_to_rad(315) && angle <= degree_to_rad(45))
    //    color = 0xFF0000;
    while((int)x++ < nheigh)
        mlx_put_pixel(exec->wind_image, rx + n, y++, color);
    while(y < (int)exec->mlxx.win_hei)
        mlx_put_pixel(exec->wind_image, rx + n, y++, exec->inf.flr_cl);
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

// int ft_check_walls(t_exec *exec, int ind)
// {
//     int i;
//     int x;
//     int y;
//     char    **map;

//     map = exec->inf.map;
//     i = 0;
//     exec->tex.ply.inc_move = SPEED;
//     if (ind == 0)
//     {
//         if(exec->tex.ply.rotangle < (M_PI))
//         {
//             if (exec->tex.ply.rotangle)
//                 y = (exec->tex.ply.py - exec->tex.ply.rds);
//             if (exec->tex.ply.rotangle < (M_PI / 2))
//                 x = (exec->tex.ply.px + exec->tex.ply.rds);
//             else
//                 x = (exec->tex.ply.px - exec->tex.ply.rds);
//         }
//         else
//         {
//              y = (exec->tex.ply.py + exec->tex.ply.rds);
//                 if (exec->tex.ply.rotangle < ((3 * M_PI) / 2))
//                 x = (exec->tex.ply.px + exec->tex.ply.rds);
//             else
//                 x = (exec->tex.ply.px - exec->tex.ply.rds);
//         }
//     }
//     else
//     {
//         if(exec->tex.ply.rotangle < (M_PI))
//         {
//             y = (exec->tex.ply.py - exec->tex.ply.rds);
//             if (exec->tex.ply.rotangle < (M_PI / 2))
//                 x = (exec->tex.ply.px - exec->tex.ply.rds);
//             else
//                 x = (exec->tex.ply.px + exec->tex.ply.rds);
//         }
//         else
//         {
//              y = (exec->tex.ply.py + exec->tex.ply.rds);
//                 if (exec->tex.ply.rotangle < ((3 * M_PI) / 2))
//                 x = (exec->tex.ply.px + exec->tex.ply.rds);
//             else
//                 x = (exec->tex.ply.px - exec->tex.ply.rds);
//         }
//     }

//     /* loop */
//     while(++i < SPEED)
//     {
//         if (ind == 0)
//         {
//             x -= cos(exec->tex.ply.rotangle) * i;
//             y -= sin(exec->tex.ply.rotangle) * i;
//         }
//         else
//         {
//             x += cos(exec->tex.ply.rotangle) * i;
//             y += sin(exec->tex.ply.rotangle) * i;
//         }
//         if (map[y / PIXELS][x / PIXELS] != '1')
//             continue ;
//         else if (i == 1)
//             return (1);
//         else
//             break ;
//     }
//     exec->tex.ply.inc_move = i - 1;
//     return(0);
// }

int     move_up(t_exec *exec)
{
    // if (ft_check_walls(exec, 0))
    //     return (0);
    exec->tex.ply.py -= sin(exec->tex.ply.rotangle) * exec->tex.ply.inc_move;
    exec->tex.ply.px -= cos(exec->tex.ply.rotangle) * exec->tex.ply.inc_move;
    return (0);
}

int move_down(t_exec *exec)
{
    // if (ft_check_walls(exec, 1))
    //     return (0);
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    return (0);
}



int move_righ(t_exec *exec)
{
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