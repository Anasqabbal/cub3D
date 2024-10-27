/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:40 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/27 16:25:42 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void draw_an_image(t_exec *exec, mlx_image_t *img, int startx, int starty)
{
    unsigned int y;
    unsigned int x;
    int color;
    unsigned int index;

    y = -1;
    while(++y < img->height - 1)
    {
        x = -1;
        while(++x < img->width)
        {
            index = ((y * img->width) + x) * 4;
            if (index < ((img->height *  img->width) + img->width) * 4 
                && index + 1 < ((img->height *  img->width) + img->width) * 4
                && index + 2 < ((img->height *  img->width) + img->width) * 4
                && index + 4 < ((img->height *  img->width) + img->width) * 4)
            color = (int)ft_pixel(img->pixels[index], img->pixels[index + 1], img->pixels[index + 2], img->pixels[index + 3]);
            if (color != 0)
                 mlx_put_pixel(exec->wind_image, startx + x, starty + y, color);
        }
    }
}
void draw_crosshair_and_wp(t_exec *exec)
{
    int i;
    int count;

    i = 5;
    count  = 0;

    while(count < 5)
    {
        mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2), (exec->info.win_hei / 2 + i), 0xff0000ff);
        mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2), (exec->info.win_hei / 2 - i), 0xff0000ff);
        mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2 + i), (exec->info.win_hei / 2), 0xff0000ff);
        mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2 - i), (exec->info.win_hei / 2), 0xff0000ff);
        i++;
        count++;
    }
}

// void clear_with_color(t_exec *exec)
// {
//     int i = -1;
//     int j = -1;
//     while(++i < exec->info.win_hei / 2)
//     {
//         j = -1;
//         while(++j < exec->info.win_wid)
//             mlx_put_pixel(exec->wind_image, j, i, exec->info.clg_cl);
//     }
//     while(i++ < exec->info.win_hei)
//     {
//         j = -1;
//         while(++j < exec->info.win_wid)
//             mlx_put_pixel(exec->wind_image, j, i, exec->info.flr_cl);
//     }
// }

// void draw_frames(t_exec *exec, mlx_image_t **imgs, int frms)
// {
//     int i = -1;
//     int count ;

//     (void)frms;
//     while ( < frms)
//     {
//         count = 0;
//         // ray_casting(exec);
//         while(count++ < 1000)
//             ;
//         draw_an_image(exec, imgs[i], 0, 0);
//     }
// }

void mouse_fun(void *ptr)
{
    t_exec *exec;

    exec = ptr;
    static     int othr;
    static     int ms;
    static int frm = 0;
    static int flg = 0;
    static int rld;
    // static int still_pressed;
    // static float curx;
    // static float cury;
    // static int upd;
    /*keys movements*/
    flg = 0;
    if (mlx_is_key_down(exec->mlx, MLX_KEY_RIGHT)  && ++flg && ++othr)
		move_right(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_LEFT) && ++flg && ++othr)
		move_left(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_W) && ++flg && ++othr && ++exec->stl.u)
		move_up(exec);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_S) && ++flg && ++othr && ++exec->stl.d)
		move_down(exec);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_D) && ++flg && ++othr && ++exec->stl.l)
		move_right(exec, 0);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_A) && ++flg && ++othr && ++exec->stl.r)
		move_left(exec, 0);
	else if ((mlx_is_key_down(exec->mlx,  MLX_KEY_ESCAPE)) || (mlx_is_key_down(exec->mlx, MLX_KEY_Q)))
		clean_and_exit(exec);

    // exec->ply.move_inc = SPEED;
    /*mouse movements*/
    mlx_get_mouse_pos(exec->mlx, &exec->ms.curx, &exec->ms.cury);
    if ((exec->ms.curx > 0 && exec->ms.curx < (int)exec->info.win_wid) && (exec->ms.cury > 0 && exec->ms.cury < (int)exec->info.win_hei) && ++ms)
    {
        mlx_set_mouse_pos(exec->mlx,  exec->info.win_wid / 2,  exec->info.win_hei / 2);
        mlx_set_cursor_mode(exec->mlx, MLX_MOUSE_HIDDEN);
        exec->ply.rotangle += ((exec->ms.curx - exec->ms.prevx) * exec->ms.sensitivity);
        fix_current_angle(&exec->ply.rotangle);
        mlx_get_mouse_pos(exec->mlx, &exec->ms.prevx, & exec->ms.prevy);
    }
    mlx_get_mouse_pos(exec->mlx, &exec->ms.prevx, & exec->ms.prevy);
    if (flg || ms)
    {
        if ((othr == exec->stl.u && exec->stl.d == 0 &&  exec->stl.l == 0 && exec->stl.r == 0) && flg)
            exec->ply.move_inc += (othr * 10);
        else
        {
            exec->ply.move_inc = SPEED;
            othr = 0;
            initialize_buttons(exec);
        }
        ray_casting(exec);
        if (mlx_is_key_down(exec->mlx,  MLX_KEY_T) || frm)
        {
            if (exec->wp.blt || frm)
            {
                draw_an_image(exec, exec->wp.sht[frm++], 0, 0);
                usleep(20000);
                if (frm == exec->wp.shtnb)
                {
                    frm = 0;
                    exec->wp.blt--;
                }
            }
        }
        else if ((mlx_is_key_down(exec->mlx,  MLX_KEY_R) || rld) && !exec->wp.blt)
        {
            draw_an_image(exec, exec->wp.rld[rld++], 0, 0);
            usleep(20000);
            if (rld == exec->wp.rldnb)
            {
                rld = 0;
                exec->wp.blt = 3;
            }
        }
        else
            draw_an_image(exec, exec->wp.hld, 0, 0);
        draw_crosshair_and_wp(exec);
        draw_mini_map(exec);
        flg = 0;
        ms = 0;
    }
}