/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:40 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/21 17:54:51 by anqabbal         ###   ########.fr       */
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
    exec->ms.prevx = exec->info.win_wid / 2;
    exec->ms.prevy = exec->info.win_hei / 2;
    mlx_get_mouse_pos(exec->mlx, &exec->ms.curx, &exec->ms.cury);
    exec->ply.rotangle += ((exec->ms.curx - exec->ms.prevx) * exec->ms.sensitivity);
    fix_current_angle(&exec->ply.rotangle);
    mlx_set_mouse_pos(exec->mlx, exec->ms.prevx, exec->ms.prevy);
    ray_casting(exec);
	draw_mini_map(exec);
    draw_crosshair_and_wp(exec);
}