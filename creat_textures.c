/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/20 17:36:54 by anqabbal         ###   ########.fr       */
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
	return (0);
}

int set_pixels_as_circle(unsigned int raduis, t_img *img)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	j;
	int				end;
	char			*image;
	int				var;

	x = 0;
	j = 0;
	end = raduis;
	y = img->ylen / 2;
	var = (raduis / 10 ) - 3;
	printf("the value of img->ylen == %u and y == %u\n", img->ylen, y);
	(void) raduis;
	image = img->image_add;
	while (y < (img->ylen))
	{
		x = j;
		while(end > 0 && x < (unsigned int) end)
		{
			*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  img->color;
			x++;
		}
		j += var;
		end -= var;
		y++;
	}
	end = raduis;
	y = img->ylen / 2;
	j = 0;
	while (y > 0)
	{
		x = j;
		while(end > 0 && x < (unsigned int) end)
		{
			*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  img->color;
			x++;
		}
		j += var;
		end -= var;
		y--;
	}
	return (0);
}

int	draw_the_player(t_exec *exec)
{
	t_img img;
	unsigned int x;
	unsigned int y;

	img.ylen = PIXELS;
	img.xlen = PIXELS;
	img.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
	img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
	set_pixels_to_image(&img);
	img.color = exec->inf.flr_cl;
	img.color = 0xDB0000;
	set_pixels_as_circle(PIXELS, &img);
	y = 0;
	x = 0;
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == 'P')
				mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, img.image, (x * PIXELS), (y * PIXELS));
			x++;
		}
		y++;
	}
	return (0);
}
