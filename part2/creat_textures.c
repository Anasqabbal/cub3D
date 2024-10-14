/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/14 18:14:47 by anqabbal         ###   ########.fr       */
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

int draw_the_floor(t_exec *exec, unsigned int y,  unsigned int x, int var)
{
	int color2;
	int	xx;
	int	yy;

	yy = 0;
	color2 = 0x04ed93aa;/*aa*/
	while (yy < var)
	{
		xx = 0;
		while(xx < var)
		{
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, 0x04ed93ff);/*ff*/
			else
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
	return (0);
}

int draw_the_walls(t_exec *exec, unsigned int y,  unsigned int x, int var)
{
	int color2;
	int	xx;
	int	yy;

	yy = 0;
	color2 = 0x00190f55;/*55*/
	while (yy < var)
	{
		xx = 0;
		while(xx < var)
		{
			if (yy != 0 && xx > 0)
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, 0x00190fff);/*ff*/
			else
				mlx_put_pixel(exec->wind_image, x + xx, y + yy, color2);
			xx++;
		}
		yy++;
	}
	return (0);
}

void draw_empty_space(t_exec *exec, unsigned int y,  unsigned int x, int var)
{
	int color2;
	int	xx;
	int	yy;

	yy = 0;
	printf("here (%d, %d)\n", y / PIXELS, x / PIXELS);
	color2 = 0x000000ff;
	while (yy < var)
	{
		xx = 0;
		while(xx < var)
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

void draw_the_player(t_exec *exec, unsigned int y,  unsigned int x, int var, int new_y)
{
	// int	xx;
	// int	yy;

	// yy = (var / 2) - 1;
	// while (yy < var)
	// {
	// 	xx =  (var / 2) - 1;
	// 	while(xx < var)
	// 	{
	// 		if (yy != 0 && xx > 0)
	// 			mlx_put_pixel(exec->wind_image, x + xx, y + yy, 0x6e022cff);
	// 		else
	// 			mlx_put_pixel(exec->wind_image, x + xx, y + yy, 0x6e022cff);
	// 		xx++;
	// 	}
	// 	yy++;
	// }
	(void)var;
	(void)new_y;
	printf("(%d, %d)\n", y, x);
	mlx_put_pixel(exec->wind_image, x , y, 0x6e022cff);
	double i;
	double nx = x;
	double ny = y;
	double new_angle;
	int j;
	
	// if (exec->info.map[(int)floor(ny / var)][(int)floor(nx / var)] != '1')
	// 	printf("anything\n");
	new_angle = exec->tex.ply.rotangle - (degree_to_rad(AOV / 2));
	j = 0;
	while ((int)j < AOV)
	{
		new_angle += degree_to_rad(1);
		i = 0.01;
		ny = y;
		nx = x;
		while(i < 6 && nx > 0 && ny > 0 && nx < exec->info.win_wid && ny < exec->info.win_hei)
		{
			// printf("your map %c\n", exec->info.map[(int)floor((ny - new_y) / var)][(int)floor(nx / var)]);
			if (nx != x )
				mlx_put_pixel(exec->wind_image, (int)nx, (int)ny,  0x6e022cff);
			nx -= cos(new_angle) * 0.1;
			ny -= sin(new_angle) * 0.1;
			i = i + 0.01;
		}
		j++;
	}
}

int one_of_these(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void draw_map(t_exec *exec, int var, int new_y)
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
				draw_the_walls(exec, (y * var) + new_y, x * var, var);
			else if (exec->info.map[y][x] == '0')
				draw_the_floor(exec, (y * var) + new_y , x * var, var);
			else if (!one_of_these(exec->info.map[y][x]))
			{
				draw_the_floor(exec, (y * var) + new_y , x * var, var);
			}
			else
				draw_empty_space(exec, (y * var) + new_y , x * var, var);
			x++;
		}
		y++;
	}
	draw_the_player(exec, (exec->tex.ply.py / get_persent(PIXELS, 10)) + new_y,  (exec->tex.ply.px / get_persent(PIXELS, 10)), var, new_y);
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
