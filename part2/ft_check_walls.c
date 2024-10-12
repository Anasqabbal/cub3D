/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:13:48 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 11:06:47 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void set_the_right_value(char ind, int *x, int *y, int i, t_exec *exec)
{
    if (ind == 0)
    {
        *x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle - degree_to_rad(90)) * i);
        *y = exec->tex.ply.py - (sin(exec->tex.ply.rotangle - degree_to_rad(90)) * i);
    }
    else if (ind == 1)
    {
        *x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle) * i);
        *y = exec->tex.ply.py - (sin(exec->tex.ply.rotangle) * i);
    }
    else if (ind == 2)
    {
        *x = exec->tex.ply.px - (cos(exec->tex.ply.rotangle + degree_to_rad(90)) * i);
        *y = exec->tex.ply.py - (sin(exec->tex.ply.rotangle + degree_to_rad(90)) * i);
    }
    else if (ind == 3)
    {
        *x = exec->tex.ply.px + (cos(exec->tex.ply.rotangle) * i);
        *y = exec->tex.ply.py + (sin(exec->tex.ply.rotangle) * i);
    }
}

int ft_check_walls(t_exec *exec, int ind)
{
    int i;
    int y;
    int x;
    int j;

    i = 0;
    j = 0;
    (void) ind;
    while(++i <= SPEED)
    {
        set_the_right_value(ind, &x, &y, i, exec);
        if (i == 1 && exec->info.map[(int)floor(y / PIXELS)][(int)floor(x / PIXELS)] == '1')
            return (0);
        else if (exec->info.map[(int)floor(y / PIXELS)][(int)floor(x / PIXELS)] == '1')
            return (exec->tex.ply.move_inc = i - 1 ,i);
    }
    exec->tex.ply.move_inc =  i - 1;
    return (i);
}
