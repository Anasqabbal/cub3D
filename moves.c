/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/24 18:03:26 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int redraw_flr_img(t_exec *exec)
{
    t_img   img;

	img.ylen =  PIXELS;
	img.xlen = PIXELS;
    img.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
    img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
    img.color = exec->inf.flr_cl;
	set_pixels_to_image(&img);
    exec->tex.flr.img = img.image;
    return (0);
}

int     move_up(t_exec *exec)
{

    // if (check_walls(1, exec->tex.ply.py - (PIXELS / 2) - 1, exec->tex.ply.px, exec))
    redraw_flr_img(exec);
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    exec->tex.ply.py -= sin(exec->tex.ply.rotangle) * SPEED;
    exec->tex.ply.px -= cos(exec->tex.ply.rotangle) * SPEED;
    ft_move_player(exec);
    return (0);
}

int move_down(t_exec *exec)
{

    // if (check_walls(1, exec->tex.ply.py + ((PIXELS / 2) + 1), exec->tex.ply.px, exec))
    //     return (0);
    redraw_flr_img(exec);
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    // s = SPEED;
    // exec->tex.ply.enddy += SPEED;
    // exec->tex.ply.enduy -= SPEED;
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * SPEED);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * SPEED);
    ft_move_player(exec);
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
    if (exec->tex.ply.rotangle > 2 * M_PI)
    {
        printf("the value of %f\n", degree_to_rad(360));
        exec->tex.ply.rotangle -= 2 * M_PI;
    }
    exec->tex.ply.rotangle += degree_to_rad(SPEED);
    printf("after R== %f\n", rad_to_degree(exec->tex.ply.rotangle));
    ft_draw_rays(exec);
    // ft_move_player(exec);
    return (0);
}

int move_left(t_exec *exec)
{
    int     s;

    s = SPEED;
    // if (check_walls(2, exec->tex.ply.py, exec->tex.ply.px - (PIXELS / 2) - 1, exec))
    //     return (0);
    // if (exec->inf.map[(exec->tex.ply.py) / PIXELS][((exec->tex.ply.px - (PIXELS / 2) - 1) / PIXELS)] == '1')
    //     return (0);
    // redraw_flr_img(exec);
    // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    if (exec->tex.ply.rotangle <= 0)
        exec->tex.ply.rotangle = degree_to_rad(360);
    exec->tex.ply.rotangle -= degree_to_rad(SPEED);
    printf("after L== %f\n", rad_to_degree(exec->tex.ply.rotangle));
    // ft_move_player(exec);
    ft_draw_rays(exec);
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
    if (key == 123 || key == 65361)
        move_left(exec);
    if (key == 126 || key == 65362)
        move_up(exec);
    if (key == 125 || key == 65364)
        move_down(exec);
    return (0);
}