/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:16 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/28 14:19:01 by anqabbal         ###   ########.fr       */
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

float adj_dimensions(t_exec *exec, int ind, int fl, int prs)
{
	int		x;
	int		y;
	float	dt;
	float		val;

	y = -1;
	val = 8.5;
	while (exec->info.map[++y])
	{
		x = -1;
		while(exec->info.map[y][++x])
		{
			if (!one_of_these(exec->info.map[y][x]) && ++fl)
				break ;
		}
		if (fl)
			break ;
	}
	if (ind == 0)
	{
		x *= PIXELS;
		dt = exec->ply.px / val - x / val;
		return (get_persent(dt, prs));
	}
	y *= PIXELS;
	dt = exec->ply.py / val - y / val;
	return (get_persent(dt, prs));
}

float bx(float angle)
{
	char righ;

	it_is_left_or_right(angle, &righ);
	if (righ)
		return (-1);
	else 
		return (1);
}

float by(float angle)
{
	char up;

	it_is_up_or_down(angle, &up);
	if (up)
		return (-1);
	else 
		return (1);
}

void	draw_the_player(t_exec *exec, int var, int new_y, int div, int prs)
{
	float	i;
	float	nx;
	float 	nxxx;
	float	pyyy;
	float	ny;
	float	new_angle;
	int		j;

	(void)div;
	(void)var;
	(void)prs;
	new_angle = exec->ply.rotangle - (degree_to_rad(AOV / 2));
	j = -1;
	while ((int)++j < AOV)
	{
		new_angle += degree_to_rad(1);
		i = 0.01;
		ny = (exec->ply.py) / (get_persent(PIXELS, 10));
		nx = (exec->ply.px) / (get_persent(PIXELS, 10));
		nxxx = exec->mm.px + (adj_dimensions(exec, 0, 0, prs));
		pyyy = exec->mm.py + (adj_dimensions(exec, 1, 0, prs)) + new_y;
		while (i < 2 && nxxx > 0 && pyyy > 0  && nxxx < exec->info.win_wid && pyyy < exec->info.win_hei)
		{
			if (!floor_or_door(exec->info.map[(int)floor((ny + (by(new_angle) / 4)) / var)][(int)floor(nx + (bx(new_angle) / 4)) / var]))
				break ;
			mlx_put_pixel(exec->wind_image, (int)nxxx, (int)pyyy, 0x6e022cff);
			nx -= cos(new_angle) * 0.1;
			nxxx -= cos(new_angle) * 0.1;
			pyyy -= sin(new_angle) * 0.1;
			ny -= sin(new_angle) * 0.1;
			i += 0.01;
		}
	}
}

float get_persent(float value, float new_v)
{
    return ((value / 100.0) * new_v);
}



void    draw_mini_map(t_exec *exec)
{
	int new_y;
	int	diff;

	diff = get_persent(PIXELS, 7);
	new_y = exec->info.win_hei - (((exec->info.map_hei / PIXELS)) * (PIXELS / get_persent(PIXELS, 10)));
	new_y = exec->info.win_hei - ((diff * 2) * (PIXELS / get_persent(PIXELS, 10)));
	fill_xstart_end(exec, &exec->mm.startx, &exec->mm.endx, diff);
	fill_ystart_end(exec, &exec->mm.starty, &exec->mm.endy, diff);
    draw_map(exec, (PIXELS / get_persent(PIXELS, 10)) , new_y);
	draw_the_player(exec, (PIXELS / get_persent(PIXELS, 10)), new_y, get_persent(PIXELS, 10), get_persent(PIXELS, 27));
}