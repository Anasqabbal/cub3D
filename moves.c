/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/30 18:06:07 by anqabbal         ###   ########.fr       */
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

void draw_the_walls11(int rx, double ry, t_exec *exec, double angle, int nro)
{
    int nheigh;
    double  ah;
    int n;
   

    (void)nro;
    (void)n;
    
    ah = (ry - exec->tex.ply.py) / cos((degree_to_rad(90) - angle));
    ah = abs((int)ah);
    nheigh  = ((PIXELS) / ah) * (PIXELS * 2); /* the new heigh of the wall that you want to draw */
    t_img img;

    img.image = mlx_new_image(exec->mlx.mlx, 1, exec->mlx.win_hei);
    img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
    img.ylen = exec->mlx.win_hei;
    img.xlen = 1;
    exec->tex.image = img.image;
    int y ;
    int x ;
    n = 0;
        y = 0;
        x = 0;
        int clg = (exec->mlx.win_hei / 2) - (nheigh);
        while(y < clg)
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++,exec->inf.clg_cl);
        while((int)x++ < nheigh) /* draw the new wall */
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, 0xFB001D);
        while(y < (int)exec->mlx.win_hei)
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w1, rx + n, y++, exec->inf.flr_cl);
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
    while((int)i < (AOV))
    {
        x = exec->tex.ply.px;
        y = exec->tex.ply.py;
        start_angle = (exec->tex.ply.rotangle - (angle_ - (i * (M_PI / 180))));
        while(exec->inf.map[(int)y / PIXELS][(int)x / PIXELS] != '1')
        {
            x -= (cos(start_angle));
            y -= (sin(start_angle));
            // if (exec->inf.map[((int)y) / PIXELS][((int)x) / PIXELS] != '1') //TODO to destroy 2d map
            //     mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, (int)x, (int)y, 0x000000); // the same
        }
        draw_the_walls11(cc++, y, exec, start_angle, i); // to destroy 3d map
        i += inc;
    }
    (void)cc;
    return (0);
}

int ft_check_walls(t_exec *exec, int ind)
{
    int i;
    int x;
    int y;
    char    **map;

    map = exec->inf.map;
    i = 0;
    exec->tex.ply.inc_move = SPEED;
    if (ind == 0)
    {
        if(exec->tex.ply.rotangle < (M_PI))
        {
            if (exec->tex.ply.rotangle)
                y = (exec->tex.ply.py - exec->tex.ply.rds);
            if (exec->tex.ply.rotangle < (M_PI / 2))
                x = (exec->tex.ply.px + exec->tex.ply.rds);
            else
                x = (exec->tex.ply.px - exec->tex.ply.rds);
        }
        else
        {
             y = (exec->tex.ply.py + exec->tex.ply.rds);
                if (exec->tex.ply.rotangle < ((3 * M_PI) / 2))
                x = (exec->tex.ply.px + exec->tex.ply.rds);
            else
                x = (exec->tex.ply.px - exec->tex.ply.rds);
        }
    }
    else
    {
        if(exec->tex.ply.rotangle < (M_PI))
        {
            y = (exec->tex.ply.py - exec->tex.ply.rds);
            if (exec->tex.ply.rotangle < (M_PI / 2))
                x = (exec->tex.ply.px - exec->tex.ply.rds);
            else
                x = (exec->tex.ply.px + exec->tex.ply.rds);
        }
        else
        {
             y = (exec->tex.ply.py + exec->tex.ply.rds);
                if (exec->tex.ply.rotangle < ((3 * M_PI) / 2))
                x = (exec->tex.ply.px + exec->tex.ply.rds);
            else
                x = (exec->tex.ply.px - exec->tex.ply.rds);
        }
    }

    /* loop */
    while(++i < SPEED)
    {
        if (ind == 0)
        {
            x -= cos(exec->tex.ply.rotangle) * i;
            y -= sin(exec->tex.ply.rotangle) * i;
        }
        else
        {
            x += cos(exec->tex.ply.rotangle) * i;
            y += sin(exec->tex.ply.rotangle) * i;
        }
        if (map[y / PIXELS][x / PIXELS] != '1')
            continue ;
        else if (i == 1)
            return (1);
        else
            break ;
    }
    exec->tex.ply.inc_move = i - 1;
    return(0);
}

int     move_up(t_exec *exec)
{
    if (ft_check_walls(exec, 0))
        return (0);
    exec->tex.ply.py -= sin(exec->tex.ply.rotangle) * exec->tex.ply.inc_move;
    exec->tex.ply.px -= cos(exec->tex.ply.rotangle) * exec->tex.ply.inc_move;
    return (0);
}

int move_down(t_exec *exec)
{
    if (ft_check_walls(exec, 1))
        return (0);
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * exec->tex.ply.inc_move);
    return (0);
}



int move_righ(t_exec *exec)
{
    if (exec->tex.ply.rotangle > (M_PI * 2))
        exec->tex.ply.rotangle -= 2 * M_PI;
    exec->tex.ply.rotangle += VIEW_SPEED;
    return (0);
}



int move_left(t_exec *exec)
{
    if (exec->tex.ply.rotangle < 0)
        exec->tex.ply.rotangle += 2 * M_PI;
    exec->tex.ply.rotangle -= VIEW_SPEED;
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
    // ft_move_player(exec);// to destroy 2d map
    trace_rays1(exec);
    return (0);
}