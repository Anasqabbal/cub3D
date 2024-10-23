/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:40 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/23 14:30:24 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void draw_crosshair_and_wp(t_exec *exec)
{
    int i;
    int count;

    i = 5;
    count  = 0;
    while(count < 5)
    {
        mlx_put_pixel(exec->wind_image, exec->info.win_wid / 2, exec->info.win_hei / 2 + i, 0xff0000ff);
        mlx_put_pixel(exec->wind_image, exec->info.win_wid / 2, exec->info.win_hei / 2 - i, 0xff0000ff);
        mlx_put_pixel(exec->wind_image, exec->info.win_wid / 2 + i, exec->info.win_hei / 2, 0xff0000ff);
        mlx_put_pixel(exec->wind_image, exec->info.win_wid / 2 - i, exec->info.win_hei / 2, 0xff0000ff);
        i++;
        count++;
    }
    mlx_image_to_window(exec->mlx, exec->wp, (exec->info.win_wid / 2),  (exec->info.win_hei / 2) + 100);
}

void mouse_fun(void *ptr)
{
    t_exec *exec;

    exec = ptr;
    /*keys movements*/
    
    if (mlx_is_key_down(exec->mlx, MLX_KEY_RIGHT))
		move_right(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_LEFT))
		move_left(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_W))
		move_up(exec);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_S))
		move_down(exec);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_D))
		move_right(exec, 0);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_A))
		move_left(exec, 0);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_ESCAPE) || mlx_is_key_down(exec->mlx, MLX_KEY_Q))
		clean_and_exit(exec);



    /*mouse movements*/
    mlx_get_mouse_pos(exec->mlx, &exec->ms.curx, &exec->ms.cury);
    if ((exec->ms.curx > 0 && exec->ms.curx < (int)exec->info.win_wid) && (exec->ms.cury > 0 && exec->ms.cury < (int)exec->info.win_hei) )
    {
        mlx_set_mouse_pos(exec->mlx,  exec->info.win_wid / 2,  exec->info.win_hei / 2);
        mlx_set_cursor_mode(exec->mlx, MLX_MOUSE_HIDDEN);
        exec->ply.rotangle += ((exec->ms.curx - exec->ms.prevx) * exec->ms.sensitivity);
        fix_current_angle(&exec->ply.rotangle);
        mlx_get_mouse_pos(exec->mlx, &exec->ms.prevx, & exec->ms.prevy);
    }
    mlx_get_mouse_pos(exec->mlx, &exec->ms.prevx, & exec->ms.prevy);
    ray_casting(exec);
	draw_mini_map(exec);
    draw_crosshair_and_wp(exec);
}
