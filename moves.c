/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/30 10:10:05 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


void set_pixels_to_image_pro(t_img *img, int nheigh, t_exec *exec)
{
    int x;
    int y;

    x = 0;
    y = 0;
    int clg = ((exec->inf.hei * PIXELS) / 2) - nheigh;
    char *image = exec->tex.image;
        while(y < clg)
        {
            x = 0;
            while(x < 4)
                *(int *)((image + ((y * img->line_) + (x++ * (img->bits_pp / 8))))) =  exec->inf.clg_cl;
            y++;
        }
		x = 0;
        int yy = 0;
        while(yy < nheigh)
        {
            x = 0;
            while(x < 4)
                *(int *)((image + ((y * img->line_) + (x++ * (img->bits_pp / 8))))) =  0xFB001D;
            yy++;
            y++;
        }
        while(y < (int)exec->mlx.win_hei)
		{
            x = 0;
            while(x < 4)
                *(int *)((image + ((y * img->line_) + (x++ * (img->bits_pp / 8))))) =  exec->inf.flr_cl;
		    y++;
		}
}

void draw_the_walls11(double rx, double ry, t_exec *exec, double angle, int nro)
{
    double ds;
    // int str;
    int nheigh;
   double  ah;
   int n;
   
    /* abchacha calcul*/

    ds = sqrt((pow(rx - exec->tex.ply.px, 2) + pow(ry - exec->tex.ply.py, 2)));
    int wall_height = (PIXELS / (ds * cos(exec->tex.ply.rotangle - (nro * (M_PI / 180))))) * ((exec->mlx.win_wid / 2) / tan(M_PI / 6));

        // int top = ft_max((1000 / 2) - (wall_height / 2), 0);
        // int    bottom = ft_min((1000 / 2) + (wall_height / 2), 1000);
   /**/
    (void)n;
    ah = (ry - exec->tex.ply.py) / cos((degree_to_rad(90) - angle));
    nheigh  = ((PIXELS) / (ds)) * PIXELS;
    // draw_map(exec);
    ah = abs((int)ah);
    // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.ply.px - (cos(angle) * (int)ah), exec->tex.ply.py - (sin(angle) * (int)ah), 0xFF0000);
    // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (exec->tex.ply.px - (cos(angle) * (int)ds)) - 1, exec->tex.ply.py - (sin(angle) * (int)ds), 0x00FF00);
    
    t_img img;

    img.image = mlx_new_image(exec->mlx.mlx, 1, exec->mlx.win_hei);
    img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
    img.ylen = exec->mlx.win_hei;
    img.xlen = 1;
    exec->tex.image = img.image;
    int y ;
    int x ;
    n = 0;
    // exec->img.color = 0xFFFFFF;
    // set_pixels_to_image(&img, exec, 0x000000);
    // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w1, exec->tex.image, rx, ry);
    // while(++n < 1)
    // {
        // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w1, img.image,rx + n, 0);
        y = 0;
        x = 0;
        int clg = ((exec->inf.hei * PIXELS) / 2) - (wall_height / 2);
        while(y < clg)
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++,exec->inf.clg_cl);
        while((int)x++ < wall_height)
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, 0xFB001D);
        while(y < (int)(exec->inf.hei * PIXELS))
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, exec->inf.flr_cl);
    // }
    // printf("height s %d %d\n", nheigh, exec->mlx.win_hei);
    (void)ry;
    (void)exec;
}

int trace_rays1(t_exec *exec)
{
    double start_angle;
    double x;
    double y;
    double i = 1;
    double angle_;
    int cc = 0;

    angle_ = degree_to_rad((AOV / 2));
    double inc = exec->tex.ply.inc;
    printf("the value of inc == %f\n", inc);
    printf("the value of inc == %f\n", angle_);
    printf("the value of inc == %d\n", AOV);
    while(i < (AOV))
    {
        x = exec->tex.ply.px;
        y = exec->tex.ply.py;
        start_angle = (exec->tex.ply.rotangle - (angle_ - (i * (M_PI / 180))));
        while(exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
        {
            x -= (cos(start_angle));
            y -= (sin(start_angle));
            // if (exec->inf.map[((int)y) / PIXELS][((int)x) / PIXELS] != '1' && (int) i == 90)
            //     mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (int)x, (int)y, 0x000000);
        }
        draw_the_walls11(x, y, exec, start_angle, i);
        i += inc;
        cc++;
    }
    printf("%d\n",cc);
    return (0);
}

int     move_up(t_exec *exec)
{
    exec->tex.ply.py -= sin(exec->tex.ply.rotangle) * SPEED;
    exec->tex.ply.px -= cos(exec->tex.ply.rotangle) * SPEED;
    return (0);
}

int move_down(t_exec *exec)
{
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * SPEED);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * SPEED);
    return (0);
}



int move_righ(t_exec *exec)
{
    if (exec->tex.ply.rotangle > (M_PI * 2))
        exec->tex.ply.rotangle -= 2 * M_PI;
    exec->tex.ply.rotangle += degree_to_rad(VIEW_SPEED);
    return (0);
}



int move_left(t_exec *exec)
{
    if (exec->tex.ply.rotangle < 0)
        exec->tex.ply.rotangle += 2 * M_PI;
    exec->tex.ply.rotangle -= degree_to_rad(VIEW_SPEED);
     return (0);
}

int catch_moves(int key, void *p)
{
    t_exec *exec;

    exec = p;
    (void)exec;
    (void)p;
    mlx_clear_window(exec->mlx.mlx, exec->mlx.mlx_w1);
    if (key == 124 || key == 65363)
        move_righ(exec);
    else if (key == 123 || key == 65361)
        move_left(exec);
    else if (key == 126 || key == 65362)
        move_up(exec);
    else if (key == 125 || key == 65364)
        move_down(exec);
    // ft_move_player(exec);
    trace_rays1(exec);
    return (0);
}