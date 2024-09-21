/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/21 15:13:53 by anqabbal         ###   ########.fr       */
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
	exec->tex.wall = img.image;
	return (0);
}




void _circle_points_on_img(char *image, int cx, int cy, int x, int y, int color, t_exec *exec)
{
	(void) color;
	int		to_center;

	to_center = cx + x;
	while(to_center != cx)
		*(int *)(image + ((to_center--)* (exec->img.bits_pp / 8) + ((cy + y) * exec->img.line_))) = exec->img.color;
	to_center = cy + y;
	while(to_center != cy)
		*(int *)(image + ((cx + x)* (exec->img.bits_pp / 8) + ((to_center--) * exec->img.line_))) = exec->img.color;
	*(int *)(image + ((cx + x )* (exec->img.bits_pp / 8) + ((cy + y) * exec->img.line_))) = exec->img.color;


	to_center = cx - x;
	while(to_center != cx)
		*(int *)(image + ((to_center++)* (exec->img.bits_pp / 8) + ((cy + y) * exec->img.line_))) = exec->img.color;
	to_center = cy + y;
	while(to_center != cy)
		*(int *)(image + ((cx - x)* (exec->img.bits_pp / 8) + ((to_center--) * exec->img.line_))) = exec->img.color;
	*(int *)(image + ((cx - x )* (exec->img.bits_pp / 8) + ((cy + y) * exec->img.line_))) = exec->img.color;


	to_center = cx + x;
	while(to_center != cx)
		*(int *)(image + ((to_center--)* (exec->img.bits_pp / 8) + ((cy - y) * exec->img.line_))) = exec->img.color;
	to_center = cy - y;
	while(to_center != cy)
		*(int *)(image + ((cx + x)* (exec->img.bits_pp / 8) + ((to_center++) * exec->img.line_))) = exec->img.color;	
	*(int *)(image + ((cx + x )* (exec->img.bits_pp / 8) + ((cy - y) * exec->img.line_))) = exec->img.color;



	to_center = cx - x;
	while(to_center != cx)
		*(int *)(image + ((to_center++)* (exec->img.bits_pp / 8) + ((cy - y) * exec->img.line_))) = exec->img.color;
	to_center = cy - y;
	while(to_center != cy)
		*(int *)(image + ((cx - x)* (exec->img.bits_pp / 8) + ((to_center++) * exec->img.line_))) = exec->img.color;
	*(int *)(image + ((cx - x )* (exec->img.bits_pp / 8) + ((cy - y) * exec->img.line_))) = exec->img.color;



	to_center = cx + y;
	while(to_center != cx)
		*(int *)(image + ((to_center--)* (exec->img.bits_pp / 8) + ((cy + x) * exec->img.line_))) = exec->img.color;
	to_center = cy + x;
	while(to_center != cy)
		*(int *)(image + ((cx + y)* (exec->img.bits_pp / 8) + ((to_center--) * exec->img.line_))) = exec->img.color;
	*(int *)(image + ((cx + y)* (exec->img.bits_pp / 8) + ((cy + x) * exec->img.line_))) = exec->img.color;




	to_center = cx - y;
	while(to_center != cx)
		*(int *)(image + ((to_center++)* (exec->img.bits_pp / 8) + ((cy + x) * exec->img.line_))) = exec->img.color;
	to_center = cy + x;
	while(to_center != cy)
		*(int *)(image + ((cx - y)* (exec->img.bits_pp / 8) + ((to_center--) * exec->img.line_))) = exec->img.color;
	*(int *)(image + ((cx - y)* (exec->img.bits_pp / 8) + ((cy + x) * exec->img.line_))) = exec->img.color;


	/*7*/
	to_center = cx + y;
	while(to_center != cx)
		*(int *)(image + ((to_center--)* (exec->img.bits_pp / 8) + ((cy + x) * exec->img.line_))) = exec->img.color;
	to_center = cy - x;
	while(to_center != cy)
		*(int *)(image + ((cx + y)* (exec->img.bits_pp / 8) + ((to_center++) * exec->img.line_))) = exec->img.color;
	*(int *)(image + ((cx + y)* (exec->img.bits_pp / 8) + ((cy - x) * exec->img.line_))) = exec->img.color;



	/* done 8*/
	to_center = cx - y;
	while(to_center != cx)
		*(int *)(image + ((to_center++)* (exec->img.bits_pp / 8) + ((cy + x) * exec->img.line_))) = exec->img.color;
	to_center = cy - x;
	while(to_center != cy)
		*(int *)(image + ((cx - y)* (exec->img.bits_pp / 8) + ((to_center++) * exec->img.line_))) = exec->img.color;
	// *(int *)(image + ((cx - y)* (exec->img.bits_pp / 8) + ((cy - x) * exec->img.line_))) = exec->img.color;
}

// Midpoint circle drawing algorithm
void draw_circle(void *mlx_ptr, void *win_ptr, int cx, int cy, int radius, int color, t_exec *exec) {
    int x = 0;
    int y = radius;
    int d = 1 - radius; // Decision parameter

    // Draw the initial points on the axes
	(void)d;
	(void)d;
	(void)mlx_ptr;
	(void)win_ptr;
	(void)cx;
	(void)cy;
    // draw_circle_points(mlx_ptr, win_ptr, cx, cy, x, y, color);
	_circle_points_on_img(exec->img.image_add, PIXELS / 2, PIXELS / 2, x, y, color, exec);

    // // Iterate over the points until x >= y
    while (x < y)
    {
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        // Draw points for the current (x, y)
        _circle_points_on_img(exec->img.image_add, PIXELS / 2, PIXELS / 2, x, y, color, exec);
    }
}


int	draw_the_player(t_exec *exec)
{
	t_img img;
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
	// set_pixels_as_circle(PIXELS, &img);
	y = 0;
	x = 0;
	if (PIXELS % 2 == 0)
		rds = PIXELS / 5 - 1;
	else
		rds = PIXELS / 5;
	exec->img = img;
	while(exec->inf.map[y])
	{
		x = 0;
		while(exec->inf.map[y][x])
		{
			if (exec->inf.map[y][x] == 'P')
			{
				// draw_a_circle(exec, x * PIXELS, y * PIXELS);
				// another_draw_a_circle(exec, 0, PIXELS / 2);
				// // another_draw_a_circle(exec, PIXELS / 2, 0);
				draw_circle(exec->mlx.mlx, exec->mlx.mlx_w, x * PIXELS, y * PIXELS, rds, 0xDB0000, exec);
				mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, img.image, x * PIXELS, y * PIXELS);
				exec->tex.ply.img = img.image;
				exec->tex.ply.rds = rds;
				exec->tex.ply.px = x * PIXELS;
				exec->tex.ply.py = y * PIXELS;
				exec->tex.ply.endlx = (x * PIXELS) / 2;
				exec->tex.ply.endrx = (x * PIXELS) / 2;
				exec->tex.ply.endly = (y * PIXELS) / 2;
				exec->tex.ply.endry = (y * PIXELS) / 2;
			}
			x++;
		}
		y++;
	}
	return (0);
}
