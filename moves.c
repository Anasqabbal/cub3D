/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/21 15:20:55 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int     move_up(t_exec *exec)
{
    (void)exec;
    printf("move up\n");
    return (0);
}

int move_down(t_exec *exec)
{
    (void)exec;
    printf("move down\n");
    return (0);
}

int move_righ(t_exec *exec)
{
    (void) exec;
    exec->tex.ply.endrx += 1;
    exec->tex.ply.endlx -= 1;
    exec->tex.ply.px += 1;
    ft_move_player(exec);
    return (0);
}

int move_left(t_exec *exec)
{
    (void)exec;
     printf("move left\n");
     return (0);
}

int catch_moves(int key, void *p)
{
    t_exec *exec;

    exec = p;
    (void)exec;
    (void)p;
    if (key == 124)
        move_righ(exec);
    if (key == 123)
        move_left(exec);
    if (key == 126)
        move_up(exec);
    if (key == 125)
        move_down(exec);
    return (0);
}