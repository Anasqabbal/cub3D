/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:16 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/14 16:30:06 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int get_persent(float value, float new)
{
    return ((value / 100.0) * new);
}

void    draw_mini_map(t_exec *exec)
{
    draw_map(exec, (PIXELS / get_persent(PIXELS, 10)) , (exec->info.win_hei - get_persent(PIXELS, 240)));
}