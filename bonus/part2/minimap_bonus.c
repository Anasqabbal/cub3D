/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:16 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/21 18:12:15 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int floor_or_door(char c)
{
	if (c == '1')
		return (0);
	else if (c == 'D')
		return (0);
	return (1);
}

float ft_tajriba(t_exec *exec)
{
	int x;
	int i;
	int j;
	float dt;

	j = -1;
	while (exec->info.map[++j])
	{
		x = -1;
		while(exec->info.map[j][++x])
		{
			if (!one_of_these(exec->info.map[j][x]))
				i = x;
		}
	}
	i *= PIXELS;
	dt = exec->ply.px - i;
	return (get_persent(dt, 10));
}

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
		nx = exec->ply.px / get_persent(PIXELS, 10);
		while (i < get_persent(PIXELS, 3) && nx > 0 && ny > 0 && nx < exec->info.win_wid && ny < exec->info.win_hei)
		{
			if (!floor_or_door(exec->info.map[(int)floor((ny - new_y) / var)][(int)floor((nx) / var)]))
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

void	fill_xstart_end(t_exec *exec, int *start, int *end, int diff)
{
	int	org_len;
	int	org_pos;

	org_len = exec->info.map_wid / PIXELS;
	org_pos = exec->ply.px / PIXELS;
	*start = org_pos - diff;
	*end = org_pos + (diff);
	if (*start < 0)
	{
		*end += *start * (-1);
		*start = 0;
	}
	else if (*end >= org_len)
	{
		*start -= (*end - org_len);
		*end = org_len;
	}
}

void    draw_mini_map(t_exec *exec)
{
	int new_y;
	int start;
	int end;
	int	diff;

	start = 0;
	diff = get_persent(PIXELS, 7);
	end = 0;
	new_y = exec->info.win_hei - (((exec->info.map_hei / PIXELS)) * (PIXELS / get_persent(PIXELS, 10)));
	fill_xstart_end(exec, &start, &end, diff);
    draw_map(exec, (PIXELS / get_persent(PIXELS, 10)) , new_y);
	printf("your new_y == %d\n", new_y);
	printf("your the real y  == %d\n",  exec->info.win_hei);
	draw_the_player(exec, (PIXELS / get_persent(PIXELS, 10)), new_y);
}