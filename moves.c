/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/28 18:12:17 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void define_the_end_position(double *y, double *x, t_exec *exec)
{
    if (exec->tex.ply.rotangle >= 0 && exec->tex.ply.rotangle < M_PI)
    {
        *y = exec->tex.ply.py - (sin(exec->tex.ply.rotangle) * PIXELS);
        if ((exec->tex.ply.rotangle < (M_PI / 2) && exec->tex.ply.rotangle >= 0) || (exec->tex.ply.rotangle < ( M_PI * 2) && exec->tex.ply.rotangle > ( M_PI * 3) / 2))
        {
            *x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle) * PIXELS);
        }
        else
        {
            if (exec->tex.ply.px < 0)
                exec->tex.ply.px *= -1;
            *x = (cos(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.px;
            if (exec->tex.ply.px < 0)
                exec->tex.ply.px *= -1;
        }
    }
    else
    {
        *y = exec->tex.ply.py + (sin(exec->tex.ply.rotangle) * PIXELS);
        if ((exec->tex.ply.rotangle <= ( M_PI * 2) && exec->tex.ply.rotangle > ( M_PI * 3) / 2) || exec->tex.ply.rotangle == 0)
        {
            *x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle) * PIXELS);
        }
        else
        {
            *x = exec->tex.ply.px + (cos(exec->tex.ply.rotangle) * PIXELS);
        }
    }
}

void draw_the_opposite(double angle, int hyp, int x, int y, t_mlx mlx)
{
    /* first find the hypotenuse*/
    /* cos = adj / hyp */
    /* hyp = cos / adj */
    /* sin = opp / hyp */
    int xx;

    printf("your hypo %d your value in rad %f\n", hyp, angle);
    double opp =  (hyp * sin(angle));
    int i = 0;
    printf("your OPP %f\n", opp);
    while(i <= ((int)opp) && i > 0)
    {
        xx = (x + i) - cos(degree_to_rad(90));
        mlx_pixel_put(mlx.mlx, mlx.mlx_w, xx , y, 0x000000);
    }
    printf("THE VALUE OF I OUTSIDE %d\n", i);
}

void draw_the_walls11(double rx, double ry, t_exec *exec)
{
    int ds;
    // int str;
    int nheigh;

    ds = sqrt(pow(rx - exec->tex.ply.px, 2) + pow(ry - exec->tex.ply.py, 2));
    // printf("DS %d\n", ds);
    nheigh  = ((exec->mlx.win_hei / 2) / ds) * exec->mlx.win_hei / 4;
    printf("height s %d %d\n", nheigh, exec->mlx.win_hei);
    (void)ry;
    (void)exec;
}

int trace_rays1(t_exec *exec)
{
    double start_angle;
    double x;
    double y;
    int i = -1;

    while(++i < (AOV))
    {
        x = exec->tex.ply.px;
        y = exec->tex.ply.py;
        start_angle = (exec->tex.ply.rotangle - degree_to_rad(((AOV / 2) - i)));
        while(exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
        {
            x -= (cos(start_angle));
            y -= (sin(start_angle));
            if (exec->inf.map[((int)y) / PIXELS][((int)x) / PIXELS] != '1')
                mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (int)x, (int)y, 0x000000);
        }
        draw_the_walls11(x, y, exec);
    }
    exit (0);
    return (0);
}

int redraw_flr_img(t_exec *exec)
{
    t_img   img;

	img.ylen =  PIXELS;
	img.xlen = PIXELS;
    exec->tex.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
    img.image_add = mlx_get_data_addr(exec->tex.image, &img.bits_pp, &img.line_, &img.endian);
    img.color = exec->inf.flr_cl;
	set_pixels_to_image(&img, exec, 0x000000);
    return (0);
}

int     move_up(t_exec *exec)
{

    // if (check_walls(1, exec->tex.ply.py - (PIXELS / 2) - 1, exec->tex.ply.px, exec))
    //     return 0;
    // redraw_flr_img(exec);
    // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    exec->tex.ply.py -= sin(exec->tex.ply.rotangle) * SPEED;
    exec->tex.ply.px -= cos(exec->tex.ply.rotangle) * SPEED;
            double x;
    double y;
    x = (cos(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.px;
    y = (sin(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.py;
    // ft_move_player(exec);
    // trace_rays1(exec);
    // bresenham_line_algo2(exec->tex.ply.py, exec->tex.ply.px, (int)y, (int)x, exec);
    return (0);
}

int move_down(t_exec *exec)
{

    // if (check_walls(1, exec->tex.ply.py + ((PIXELS / 2) + 1), exec->tex.ply.px, exec))
    //     return (0);
    // redraw_flr_img(exec);
    // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    // s = SPEED;
    // exec->tex.ply.enddy += SPEED;
    // exec->tex.ply.enduy -= SPEED;
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * SPEED);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * SPEED);
        double x;
    double y;
    x = (cos(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.px;
    y = (sin(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.py;
    // ft_move_player(exec);
    // trace_rays1(exec);
    // bresenham_line_algo2(exec->tex.ply.py, exec->tex.ply.px, (int)y, (int)x, exec);
    return (0);
}



int move_righ(t_exec *exec)
{
    // if (check_walls(2, exec->tex.ply.py, exec->tex.ply.px + (PIXELS / 2) + 1, exec))
    //     return (0);
    // redraw_flr_img(exec);
    // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img ,exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    
    /* draw a black point to see if you in the right position */
    /* initialize rotation */
    // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.ply.px, exec->tex.ply.py, 0xFFFFFF);
    // printf("Player position == (%d,%d)\n",exec->tex.ply.py, exec->tex.ply.px);
    // printf("rotangelbefore == %f\n", rad_to_degree(exec->tex.ply.rotangle));
    exec->tex.ply.rotangle += degree_to_rad(VIEW_SPEED);
    if (exec->tex.ply.rotangle > (2 * M_PI))
        exec->tex.ply.rotangle -= 2 * M_PI;
    mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.ply.px, exec->tex.ply.py, 0x3A00FF);
    double x;
    double y;
    x = (cos(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.px;
    y = (sin(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.py;
    // ft_move_player(exec);
    // // bresenham_line_algo2(exec->tex.ply.py, exec->tex.ply.px, (int)y, (int)x, exec);
    // trace_rays1(exec);
    return (0);
}



int move_left(t_exec *exec)
{
    // if (check_walls(2, exec->tex.ply.py, exec->tex.ply.px - (PIXELS / 2) - 1, exec))
    //     return (0);
    if (exec->tex.ply.rotangle <= 0)
        exec->tex.ply.rotangle += 2 * M_PI;
    exec->tex.ply.rotangle -= degree_to_rad(VIEW_SPEED);
    // double x;
    // double y;
    // // x = (cos(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.px;
    // // y = (sin(exec->tex.ply.rotangle) * PIXELS) + exec->tex.ply.py;
    // // // define_the_end_position(&y, &x, exec);
    // // mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, x, y, 0x3A00FF);
    // ft_move_player(exec);
    // // bresenham_line_algo2(exec->tex.ply.py, exec->tex.ply.px, (int)y, (int)x, exec);
    trace_rays1(exec);
     return (0);
}

int catch_moves(int key, void *p)
{
    t_exec *exec;

    exec = p;
    (void)exec;
    (void)p;
    if (key == 124 || key == 65363)
        move_righ(exec);
    else if (key == 123 || key == 65361)
        move_left(exec);
    else if (key == 126 || key == 65362)
        move_up(exec);
    else if (key == 125 || key == 65364)
        move_down(exec);
    ft_move_player(exec);
    trace_rays1(exec);
    return (0);
}