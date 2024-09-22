/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/22 17:25:29 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_pixels_to_image(t_img *img)
{
	unsigned int	x;
	unsigned int	y;
	char			*image;

	x = 0;
	y = 0;
	image = img->image_add;
	while (y < (img->ylen))
	{
		x = 0;
		while(x < (img->xlen))
		{
			*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  img->color;
			x++;
		}
		y++;
	}
}

int draw_the_floor(t_exec *exec)
{
	t_img img;

	img.ylen = exec->inf.hei * PIXELS;
	img.xlen = exec->inf.wid * PIXELS;
	img.image = mlx_new_image(exec->mlx.mlx, (exec->inf.wid * PIXELS), (exec->inf.hei * PIXELS));
	img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
	img.color = exec->inf.flr_cl;
	set_pixels_to_image(&img);
	mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, img.image, 0, 0);
	
	img.ylen =  PIXELS;
	img.xlen = PIXELS;
	img.color = exec->inf.flr_cl;
	img.image = mlx_new_image(exec->mlx.mlx, (PIXELS), (PIXELS));
	img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
	exec->tex.flr.img = img.image;
	return (0);
}

int draw_the_walls(t_exec *exec)
{
	t_img img;
	unsigned int x;
	unsigned int y;

	img.ylen = PIXELS;
	img.xlen = PIXELS;
	img.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
	img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
	img.color = 0x6B6969;
	set_pixels_to_image(&img);
	y = 0;
	x = 0;
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == '1')
				mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, img.image, (x * PIXELS), (y * PIXELS));
			x++;
		}
		y++;
	}
	exec->tex.wall = img.image;
	return (0);
}


int	draw_the_player(t_exec *exec)
{
	t_img img;
	t_cir	cir;
	unsigned int x;
	unsigned int y;
	int			rds;

	img.ylen = PIXELS;
	img.xlen = PIXELS;
	img.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
	img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
	img.color = exec->inf.flr_cl;
	set_pixels_to_image(&img);
	img.color = 0xDB0000;
	y = 0;
	x = 0;
	if (PIXELS % 2 == 0)
		rds = PIXELS / 2 - 1;
	else
		rds = PIXELS / 2;
	exec->img = img;
	cir.rds = rds;
	cir.to_fill = 0;
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == 'P')
			{
				cir.cx = (x * PIXELS) + (PIXELS / 2);
				cir.cy = (y * PIXELS) + (PIXELS / 2);
				draw_circle(exec, &cir);
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
			}
			x++;
		}
		y++;
	}
	return (0);
}
