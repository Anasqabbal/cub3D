/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:40 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/16 20:02:18 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void mouse_fun(void *ptr)
{
    t_exec *exec;

    exec = ptr;
    exec->ms.prevx = exec->info.win_wid / 2;
    exec->ms.prevy = exec->info.win_hei / 2;
    mlx_get_mouse_pos(exec->mlx, &exec->ms.curx, &exec->ms.cury);
    exec->tex.ply.rotangle += ((exec->ms.curx - exec->ms.prevx) * exec->ms.sensitivity);
    fix_current_angle(&exec->tex.ply.rotangle);
    mlx_set_mouse_pos(exec->mlx, exec->ms.prevx, exec->ms.prevy);
    ray_casting(exec);
    draw_mini_map(exec);
}