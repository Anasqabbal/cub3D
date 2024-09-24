/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:13:48 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/24 08:39:18 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_if(int ind, int i)
{
    if (ind == 1 && i < PIXELS)
        return (0);
    else if (ind == 1)
        return (1);
    if (ind == 2 && i > 0)
        return (0);
    else if (ind == 2)
        return (1);
    return (0);
}

int check_walls(int ind, int y, int x, t_exec *exec)
{
    int i;
    int k;

    k = 0;
    while(++k <= 2)
    {
        i = PIXELS / 2;
        if (k == 2 && ind == 2)
            y -= (PIXELS / 2);
        if (k == 2 && ind == 1)
            x -= (PIXELS / 2);
        while (!check_if(k, i))
        {
            if (ind == 1 && exec->inf.map[y / PIXELS][x / PIXELS] == '1')
                return (1);
            else if (ind == 1 && k == 1)
            {
                x++;
                i++;

            }
            else if (ind == 1 && k == 2)
            {
                x--;
                i--;
            }
            if (ind == 2 && exec->inf.map[(y / PIXELS)][(x / PIXELS)] == '1')
                return (1);
            else if (ind == 2 && k == 1)
            {
                y++;
                i++;
            }
            else if (ind == 2 && k == 2)
            {
                y--;
                i--;
            }
        }
    }
    return (0);
}
