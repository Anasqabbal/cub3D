/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/24 18:12:39 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void bresenhams_line_algo(t_exec *exec, double endy, double endx)
{
    double subx;
    double suby;
    double m;

    subx = endx - exec->tex.ply.px;
    suby = endy - exec->tex.ply.py;

    if (subx != 0)
        m = suby / subx;
        
}

int ft_dda_algo(t_exec *exec, double endy, double endx)
{
    double m;
    double starty;
    double startx;

    starty = exec->tex.ply.py;
    startx = exec->tex.ply.px;
    m = (endy - starty) / (endx - startx);
    int i = 1;
    while(i < 30)
    {
        if (m < 1)
        {
            startx += 1;
            starty += m;
        }
        else if (m > (double)1)
        {
            startx += 1;
            starty += (1 / m);
        }
        else
        {
            startx += 1;
            starty += 1;
        }
        mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, startx, starty, 0x000000);
        i++;
    }
    return (0);
}

void ft_draw_rays(t_exec *exec)
{
    exec->line.x = exec->tex.ply.px + (cos(exec->tex.ply.rotangle) * SPEED);
    exec->line.y = exec->tex.ply.py + (sin(exec->tex.ply.rotangle) * SPEED);
    mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, exec->line.x, exec->line.y, 0x000000);
    printf("TRGET (%d, %d)\n",  exec->line.y,  exec->line.x);
    ft_dda_algo(exec, exec->line.y,  exec->line.y);
}

int start_cub(char **av)
{
    t_exec exec;

    if (init_structs(&exec, 0, av) < 0)
        return (-1);
    creat_and_start_awindow(&exec.mlx);
    draw_the_floor(&exec);
    draw_the_walls(&exec);
    draw_the_player(&exec);
    mlx_hook(exec.mlx.mlx_w, 2, 0, catch_moves, &exec);
    // mlx_key_hook(exec.mlx.mlx_w, catch_moves, &exec);
    mlx_loop(exec.mlx.mlx);
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (ft_putstr_fd("invalide argument\n", 2), 1);
    if (start_cub(av) < 0)
        return (1);
}