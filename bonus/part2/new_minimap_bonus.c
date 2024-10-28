/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_minimap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:31:25 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/28 12:49:19 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"


void new_minimap(t_exec *exec)
{
	int new_y;
	float	diff;
    float   diff2;

    diff2 = 8.50;
	diff = get_persent(PIXELS, 7) / diff2;
	new_y = exec->info.win_hei - (((exec->info.map_hei / PIXELS)) * (PIXELS / get_persent(PIXELS, 10)));
	new_y = exec->info.win_hei - ((diff * 2) * (PIXELS / get_persent(PIXELS, 10)));
	fill_xstart_end(exec, &exec->mm.startx, &exec->mm.endx, diff);
	fill_ystart_end(exec, &exec->mm.starty, &exec->mm.endy, diff);
    draw_map(exec, (PIXELS / get_persent(PIXELS, 10)) , new_y);
	draw_the_player(exec, (PIXELS / get_persent(PIXELS, 10)), new_y, get_persent(PIXELS, 10), get_persent(PIXELS, 27) / diff2);
}