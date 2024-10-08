/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/08 16:32:10 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	color2 = 0xc7c7c7c7;
	while (yy < PIXELS)
	{
		xx = 0;
		while(xx < PIXELS)
		{
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, exec->inf.flr_cl);
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
	color2 = 0x00000000;
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
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == '1')
				draw_the_walls(exec, y * PIXELS, x * PIXELS);
			else if (!one_of_this(exec->inf.map[y][x]))
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
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == 'N' || exec->inf.map[y][x] == 'S' || exec->inf.map[y][x] == 'E' || exec->inf.map[y][x] == 'W' || exec->inf.map[y][x] == 'P')
			{
				exec->tex.ply.color = 0xB00000FF;
				exec->tex.ply.rds = PIXELS / 6;
				exec->tex.ply.px = (x * PIXELS) + (PIXELS / 2);
				exec->tex.ply.py = (y * PIXELS) + (PIXELS / 2);
				exec->tex.ply.endlx = (x * PIXELS) / 2;
				exec->tex.ply.endrx = (x * PIXELS) / 2;
				exec->tex.ply.enduy = (y * PIXELS) / 2;
				exec->tex.ply.enddy = (y * PIXELS) / 2;
				exec->tex.ply.rays = (exec->mlxx.win_wid - 2);
				exec->tex.ply.inc = AOV / exec->tex.ply.rays;
				exec->tex.ply.inc_move = SPEED;
				if (exec->inf.map[y][x] == 'N')
				{
					exec->tex.ply.rotangle = degree_to_rad(90);
					// mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, xx, yy, 0x000000);

				}
				if (exec->inf.map[y][x] == 'S')
					exec->tex.ply.rotangle = degree_to_rad(270);
				if (exec->inf.map[y][x] == 'W')
					exec->tex.ply.rotangle = degree_to_rad(180);
				if (exec->inf.map[y][x] == 'E')
					exec->tex.ply.rotangle = degree_to_rad(0);
				// trace_rays1(exec);
				// ray_casting(exec);
				// mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr, x * (PIXELS), y * PIXELS);
				// draw_circle(exec, &cir);
				// mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.ply.px, exec->tex.ply.py, 0x000000);
				// trace_rays1(exec);
				// bresenhams_line_algo(exec, yy, xx);
			}
			x++;
		}
		y++;
	}
	return (0);
}
