/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/05 14:10:13 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_an_image(t_exec *exec, mlx_image_t *img, int startx, int starty)
{
	unsigned int	y;
	unsigned int	x;
	int				color;
	unsigned int	index;

	y = -1;
	while (++y < img->height - 1)
	{
		x = -1;
		while (++x < img->width)
		{
			index = ((y * img->width) + x) * 4;
			if (index < ((img->height * img->width) + img->width) * 4
				&& index + 1 < ((img->height * img->width) + img->width) * 4
				&& index + 2 < ((img->height * img->width) + img->width) * 4
				&& index + 4 < ((img->height * img->width) + img->width) * 4)
				color = (int)ft_pixel(img->pixels[index], img->pixels[index
						+ 1], img->pixels[index + 2], img->pixels[index + 3]);
			if (color != 0 && (startx + x)
				< exec->info.win_wid && (starty + y) < exec->info.win_hei)
				mlx_put_pixel(exec->wind_image, startx + x, starty + y, color);
		}
	}
}

static void	draw_color(t_exec *exec, unsigned int y, unsigned int x, int var)
{
	int	xx;
	int	yy;

	yy = 0;
	while (yy < var)
	{
		xx = 0;
		while (xx < var)
		{
			if (xx >= 0 && x + xx < exec->info.win_wid
				&& y + yy < exec->info.win_hei)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, exec->mm.color);
			xx++;
		}
		yy++;
	}
}

static void	set_info_ply(t_exec *exec, int var)
{
	exec->mm.px = exec->mm.i * var;
	exec->mm.py = exec->mm.j * var;
	exec->mm.color = 0x000000ff;
}

void	draw_map(t_exec *exec, int var, int new_y)
{
	unsigned int	y;
	unsigned int	x;

	y = exec->mm.starty - 1;
	exec->mm.j = -1;
	while (++exec->mm.j <= (exec->mm.endy) && exec->info.map[++y])
	{
		x = exec->mm.startx - 1;
		exec->mm.i = 0;
		while (exec->info.map[y][++x] && (int)x <= exec->mm.endx)
		{
			if (exec->info.map[y][x] == '1')
				exec->mm.color = 0xffffffff;
			else if (exec->info.map[y][x] == '0')
				exec->mm.color = 0x000000ff;
			else if (exec->info.map[y][x] == exec->ply.ply_char)
				set_info_ply(exec, var);
			else if (exec->info.map[y][x] == 'D')
				exec->mm.color = 0x922B21ff;
			else
				exec->mm.color = 0xc5c5c5ff;
			draw_color(exec, (exec->mm.j * var) + new_y, exec->mm.i * var, var);
			exec->mm.i++;
		}
	}
}
