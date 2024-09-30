/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/30 15:31:20 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_pixels_to_image(t_img *img, t_exec *exec, int color)
{
	unsigned int	x;
	unsigned int	y;
	char			*image;

	x = 0;
	y = 0;
	(void) exec;
	image = img->image_add;
	while (y < (img->ylen))
	{
		x = 0;
		while(x < (img->xlen))
		{
			if (y != 0 && x > 2)
				*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  img->color;
			else
				*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  color;
			x++;
		}
		y++;
	}
}

int draw_the_floor(t_exec *exec)
{
	t_img	img;

	img.ylen =  PIXELS;
	img.xlen = PIXELS;
	img.color = exec->inf.flr_cl;
	exec->tex.image = mlx_new_image(exec->mlx.mlx, (PIXELS), (PIXELS));
	img.image_add = mlx_get_data_addr(exec->tex.image, &img.bits_pp, &img.line_, &img.endian);
	set_pixels_to_image(&img, exec, img.color);
	exec->tex.flr = exec->tex.image;
	return (0);
}

int draw_the_walls(t_exec *exec)
{
	t_img img;

	img.ylen = PIXELS;
	img.xlen = PIXELS;
	exec->tex.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
	img.image_add = mlx_get_data_addr(exec->tex.image, &img.bits_pp, &img.line_, &img.endian);
	img.color = 0xbbbbbb ;
	set_pixels_to_image(&img, exec, 0x000000);
	exec->tex.wall = exec->tex.image;
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
				mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.wall, (x * PIXELS), (y * PIXELS));
			else if (!one_of_this(exec->inf.map[y][x]))
				mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr, (x * PIXELS), (y * PIXELS));
			x++;
		}
		y++;
	}
}

int	draw_the_player(t_exec *exec)
{
	t_img img;
	t_cir	cir;
	unsigned int x;
	unsigned int y;
	int			rds;

	img.color = 0xDB0000;
	y = 0;
	x = 0;
	if (PIXELS % 2 == 0)
		rds = PIXELS / 6 - 1;
	else
		rds = PIXELS / 6;
	exec->img = img;
	cir.rds = rds;
	cir.to_fill = 0;
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == 'N' || exec->inf.map[y][x] == 'S' || exec->inf.map[y][x] == 'E' || exec->inf.map[y][x] == 'W' || exec->inf.map[y][x] == 'P')
			{
				cir.cx = (x * PIXELS) + (PIXELS / 2);
				cir.cy = (y * PIXELS) + (PIXELS / 2);
				if (cir.to_fill)
					exec->tex.ply.img = img.image;
				else
					exec->tex.ply.img = NULL;
				exec->tex.ply.rds = rds;
				exec->tex.ply.px = (x * PIXELS) + (PIXELS / 2);
				exec->tex.ply.py = (y * PIXELS) + (PIXELS / 2);
				exec->tex.ply.endlx = (x * PIXELS) / 2;
				exec->tex.ply.endrx = (x * PIXELS) / 2;
				exec->tex.ply.enduy = (y * PIXELS) / 2;
				exec->tex.ply.enddy = (y * PIXELS) / 2;
				exec->tex.ply.rays = exec->mlx.win_wid;
				exec->tex.ply.inc = AOV / exec->tex.ply.rays;
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
				trace_rays1(exec);
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
