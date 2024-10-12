/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 11:06:47 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void set_pixels_to_image(t_exec *exec, int color1, int color2)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < PIXELS)
	{
		x = 0;
		while(x < PIXELS)
		{
			if (y != 0 && x > 0)
				mlx_put_pixel(exec->image, x, y, color1);
			else
				mlx_put_pixel(exec->image, x, y, color2);
			x++;
		}
		y++;
	}
}

int draw_the_floor(t_exec *exec, unsigned int y,  unsigned int x)
{
	int color2;
	int	xx;
	int	yy;

	yy = 0;
	color2 = 0xe6f1fae6;
	while (yy < PIXELS)
	{
		xx = 0;
		while(xx < PIXELS)
		{
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, exec->info.flr_cl);
			else
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
	return (0);
}

int draw_the_walls(t_exec *exec, unsigned int y,  unsigned int x)
{
	int color2;
	int	xx;
	int	yy;

	yy = 0;
	color2 = 0xfcba03fc;
	while (yy < PIXELS)
	{
		xx = 0;
		while(xx < PIXELS)
		{
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, 0xbbbbbbbb);
			else
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
	return (0);
}

int one_of_this(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void draw_map(t_exec *exec)
{
	int y;
	int x;

	y = 0;
	while(exec->info.map[y])
	{
		x = 0;
		while(exec->info.map[y][x])
		{
			if (exec->info.map[y][x] == '1')
				draw_the_walls(exec, y * PIXELS, x * PIXELS);
			else if (!one_of_this(exec->info.map[y][x]))
				draw_the_floor(exec, y * PIXELS, x * PIXELS);
			x++;
		}
		y++;
	}
}


int	set_player_info(t_exec *exec)
{
	unsigned int x;
	unsigned int y;

	y = 0;
	while(exec->info.map[y])
	{
		x = 0;
		while(exec->info.map[y][x])
		{
			if (exec->info.map[y][x] == 'N' || exec->info.map[y][x] == 'S' || exec->info.map[y][x] == 'E' || exec->info.map[y][x] == 'W' || exec->info.map[y][x] == 'P')
			{
				exec->tex.ply.color = 0xB00000FF;
				exec->tex.ply.rds = PIXELS / 6;
				exec->tex.ply.px = (x * PIXELS) + (PIXELS / 2);
				exec->tex.ply.py = (y * PIXELS) + (PIXELS / 2);
				exec->tex.ply.endlx = (x * PIXELS) / 2;
				exec->tex.ply.endrx = (x * PIXELS) / 2;
				exec->tex.ply.enduy = (y * PIXELS) / 2;
				exec->tex.ply.enddy = (y * PIXELS) / 2;
				exec->tex.ply.rays = exec->info.win_wid;
				exec->tex.ply.rays_inc = AOV / exec->tex.ply.rays;
				exec->tex.ply.move_inc = SPEED;
				if (exec->info.map[y][x] == 'N')
					exec->tex.ply.rotangle = degree_to_rad(90);
				else if (exec->info.map[y][x] == 'S')
					exec->tex.ply.rotangle = degree_to_rad(270);
				else if (exec->info.map[y][x] == 'W')
					exec->tex.ply.rotangle = degree_to_rad(180);
				else if (exec->info.map[y][x] == 'E')
					exec->tex.ply.rotangle = degree_to_rad(0);
			}
			x++;
		}
		y++;
	}
	return (0);
}
