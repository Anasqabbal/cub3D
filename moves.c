/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/22 18:07:12 by anqabbal         ###   ########.fr       */
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
    int     s;
    if (exec->inf.map[((exec->tex.ply.py - (PIXELS / 2)) / PIXELS) - 1][((exec->tex.ply.px - (PIXELS / 2)) / PIXELS)] == '1')
        return (0);
    redraw_flr_img(exec);
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    s = STEPS;
    exec->tex.ply.enduy += STEPS;
    exec->tex.ply.enddy -= STEPS;
    exec->tex.ply.py -= STEPS;
    ft_move_player(exec);
    return (0);
}

int move_down(t_exec *exec)
{
    int     s;

    redraw_flr_img(exec);
    if (exec->inf.map[((exec->tex.ply.py - (PIXELS  / 2)) / PIXELS) + 1][((exec->tex.ply.px + (PIXELS / 2)) / PIXELS)] == '1')
        return (0);
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    s = STEPS;
    exec->tex.ply.enddy += STEPS;
    exec->tex.ply.enduy -= STEPS;
    exec->tex.ply.py += STEPS;
    ft_move_player(exec);
    return (0);
}

int move_righ(t_exec *exec)
{
    int     s;

    printf("%c\n", exec->inf.map[exec->tex.ply.py / PIXELS][(exec->tex.ply.px / PIXELS) + 1]);
    if (exec->inf.map[(exec->tex.ply.py - (PIXELS / 2)) / PIXELS][((exec->tex.ply.px - (PIXELS / 2)) / PIXELS) + 1] == '1')
        return (0);
    printf("BBD%d\n", exec->tex.ply.endlx - STEPS);
    redraw_flr_img(exec);
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img ,exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    s = STEPS;
    exec->tex.ply.endrx += STEPS;
    exec->tex.ply.endlx -= STEPS;
    exec->tex.ply.px += STEPS;
    ft_move_player(exec);
    return (0);
}

int move_left(t_exec *exec)
{
    int     s;

    s = STEPS;
    printf("%c\n", exec->inf.map[(exec->tex.ply.py + (PIXELS / 2)) / PIXELS][((exec->tex.ply.px + (PIXELS / 2)) / PIXELS) - 1]);
    if (exec->inf.map[(exec->tex.ply.py + (PIXELS / 2)) / PIXELS][((exec->tex.ply.px + (PIXELS / 2)) / PIXELS) - 1] == '1')
        return (0);
    printf("hna\n");
    redraw_flr_img(exec);
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px - (PIXELS / 2),  exec->tex.ply.py - (PIXELS / 2));
    exec->tex.ply.endrx -= STEPS;
    exec->tex.ply.endlx += STEPS;
    exec->tex.ply.px -= STEPS;
    ft_move_player(exec);
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