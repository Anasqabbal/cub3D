/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_element_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/26 17:06:12 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	draw_the_floor(t_exec *exec, unsigned int y, unsigned int x, int var)
{
	int	color2;
	int	xx;
	int	yy;

	yy = 0;
	// color2 = 0x04ed93aa;
	color2 = 0x04ed93aa;
	color2 = 0x000000ff;
	while (yy < var)
	{
		xx = 0;
		while (xx < var)
		{
			/*0x04ed93ff*/
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			else
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
	return (0);
}

int	draw_the_walls(t_exec *exec, unsigned int y, unsigned int x, int var)
{
	int	color2;
	int	xx;
	int	yy;

	yy = 0;
	color2 = 0x00190f55;
	color2 = 0xffffffff;
	while (yy < var)
	{
		xx = 0;
		while (xx < var)
		{
			if (yy != 0 && xx >= 0 && x + xx <= exec->info.win_wid && x + xx >= 0 && y + yy <= exec->info.win_hei && yy + y >= 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			else if (x + xx <= exec->info.win_wid && x + xx > 0  && y + yy <= exec->info.win_hei && yy + y >= 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
	return (0);
}

void	draw_empty_space(t_exec *exec, unsigned int y, unsigned int x, int var)
{
	int	color2;
	int	xx;
	int	yy;

	yy = 0;
	color2 = 0x000000ff;
	while (yy < var)
	{
		xx = 0;
		while (xx < var)
		{
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, 0x000000ff);
			else
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
}

int	one_of_these(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void	draw_map(t_exec *exec, int var, int new_y)
{
	int	y;
	int	x;

	y = exec->mm.starty - 1;
	exec->mm.j = 0;
	while (exec->mm.j < (exec->mm.endy - 1) && exec->info.map[++y])
	{
		x = exec->mm.startx - 1;
		exec->mm.i = 0;
		while (exec->info.map[y][++x] && x < exec->mm.endx)
		{
			if (exec->info.map[y][x] == '1')
				draw_the_walls(exec, (exec->mm.j * var) + new_y, (exec->mm.i++ * var), var);
			else if (exec->info.map[y][x] == '0')
				draw_the_floor(exec, (exec->mm.j * var) + new_y, (exec->mm.i++ * var), var);
			else if (exec->info.map[y][x] == exec->ply.ply_char)
			{
				exec->mm.px = exec->mm.i * var;
				exec->mm.py = exec->mm.j * var;
				draw_the_floor(exec, (exec->mm.j * var) + new_y, (exec->mm.i++ * var), var);
			}
			else
				draw_empty_space(exec, (exec->mm.j * var) + new_y, (exec->mm.i++ * var), var);
		}
		exec->mm.j++;
	}
}
