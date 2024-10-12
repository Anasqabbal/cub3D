/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_moves_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:18:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 11:47:18 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_clean_and_exit(t_exec *exec)
{
    to_free_cub(exec->info.map);
    mlx_delete_image(exec->mlx, exec->wind_image);
    exit (0);
}

void move_left(t_exec *exec, char ind)
{
    if (ind == 0)
    {
        if (!ft_check_walls(exec, 0))
            return ;
        exec->tex.ply.py -= (sin(exec->tex.ply.rotangle - degree_to_rad(90)) * exec->tex.ply.move_inc);
        exec->tex.ply.px -= (cos(exec->tex.ply.rotangle - degree_to_rad(90)) * exec->tex.ply.move_inc);
    }
    else
    {
        exec->tex.ply.rotangle -= VIEW_SPEED;
        if (exec->tex.ply.rotangle < (double)0)
            exec->tex.ply.rotangle += 2 * M_PI;
    }
}

void     move_up(t_exec *exec)
{
    if (!ft_check_walls(exec, 1))
        return ;
    exec->tex.ply.py -= (sin(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
    exec->tex.ply.px -= (cos(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
}

void move_right(t_exec *exec, char ind)
{
    if (ind == 0)
    {
        if (!ft_check_walls(exec, 2))
            return ;
        exec->tex.ply.py -= (sin(exec->tex.ply.rotangle + degree_to_rad(90)) * exec->tex.ply.move_inc);
        exec->tex.ply.px -= (cos(exec->tex.ply.rotangle + degree_to_rad(90)) * exec->tex.ply.move_inc);
    }
    else
    {
        if (exec->tex.ply.rotangle > (M_PI * 2))
            exec->tex.ply.rotangle -= 2 * M_PI;
        exec->tex.ply.rotangle += VIEW_SPEED;
    }
}

void move_down(t_exec *exec)
{
    if (!ft_check_walls(exec, 3))
        return ;
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
}