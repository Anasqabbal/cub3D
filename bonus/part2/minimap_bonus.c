/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:16 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/18 17:45:49 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_the_player(t_exec *exec, int var, int new_y)
{
	float	i;
	float	nx;
	float	ny;
	float	new_angle;
	int		j;

	new_angle = exec->ply.rotangle - (degree_to_rad(AOV / 2));
	j = 0;
	while ((int)j < AOV)
	{
		new_angle += degree_to_rad(1);
		i = 0.01;
		ny = (exec->ply.py / get_persent(PIXELS, 10)) + new_y;
		nx = (exec->ply.px / get_persent(PIXELS, 10));
		while (i < get_persent(PIXELS, 5) && nx > 0 && ny > 0 && nx < exec->info.win_wid && ny < exec->info.win_hei)
		{
			if (exec->info.map[(int)floor((ny - new_y) / var)][(int)floor(nx / var)] == '1')
				break ;
			mlx_put_pixel(exec->wind_image, (int)nx, (int)ny, 0x6e022cff);
			nx -= cos(new_angle) * 0.1;
			ny -= sin(new_angle) * 0.1;
			i = i + 0.01;
		}
		j++;
	}
}

float get_persent(float value, float new)
{
    return ((value / 100.0) * new);
}

void    draw_mini_map(t_exec *exec)
{
    draw_map(exec, (PIXELS / get_persent(PIXELS, 10)) , (exec->info.win_hei - get_persent(PIXELS, 240)));
    draw_the_player(exec, (PIXELS / get_persent(PIXELS, 10)), (exec->info.win_hei - get_persent(PIXELS, 240)));
}