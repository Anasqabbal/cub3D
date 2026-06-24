/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:16 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/29 14:51:11 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static float	bx(float angle)
{
	char	righ;

	it_is_left_or_right(angle, &righ);
	if (righ)
		return (-1);
	else
		return (1);
}

static float	by(float angle)
{
	char	up;

	it_is_up_or_down(angle, &up);
	if (up)
		return (-1);
	else
		return (1);
}

static void	second_while(t_exec *exec, int prs, float new_angle, int var)
{
	float	nxxx;
	float	pyyy;
	float	nx;
	float	ny;
	float	i;

	ny = (exec->ply.py) / (get_persent(PIXELS, 10));
	nx = (exec->ply.px) / (get_persent(PIXELS, 10));
	nxxx = exec->mm.px + (adj_dimensions(exec, 0, 0, prs));
	pyyy = exec->mm.py + (adj_dimensions(exec, 1, 0, prs)) + exec->mm.new_y;
	i = 0.01;
	while (i < 2 && nxxx > 0 && pyyy > 0
		&& nxxx < exec->info.win_wid && pyyy < exec->info.win_hei)
	{
		if (!door_or_wall(NULL, exec->info.map
				[(int)floor((ny + (by(new_angle) / 4)) / var)]
				[(int)floor(nx + (bx(new_angle) / 4)) / var]))
			break ;
		mlx_put_pixel(exec->wind_image, (int)nxxx, (int)pyyy, 0x6e022cff);
		nx -= cos(new_angle) * 0.1;
		nxxx -= cos(new_angle) * 0.1;
		pyyy -= sin(new_angle) * 0.1;
		ny -= sin(new_angle) * 0.1;
		i += 0.01;
	}
}

void	draw_the_player(t_exec *exec, int var, int prs)
{
	float	new_angle;
	int		j;

	new_angle = exec->ply.rotangle - (degree_to_rad(AOV / 2));
	j = -1;
	while ((int)++j < AOV)
	{
		new_angle += degree_to_rad(1);
		second_while(exec, prs, new_angle, var);
	}
}

void	draw_mini_map(t_exec *exec)
{
	int		new_y;
	float	diff;
	float	diff2;

	diff2 = 8.50;
	diff = get_persent(PIXELS, 7) / diff2;
	new_y = exec->info.win_hei - ((diff * 2)
			* (PIXELS / get_persent(PIXELS, 10)));
	exec->mm.new_y = new_y;
	fill_xstart_end(exec, &exec->mm.startx, &exec->mm.endx, diff);
	fill_ystart_end(exec, &exec->mm.starty, &exec->mm.endy, diff);
	draw_map(exec, (PIXELS / get_persent(PIXELS, 10)), new_y);
	draw_the_player(exec,
		(PIXELS / get_persent(PIXELS, 10)), get_persent(PIXELS, 27) / diff2);
}
