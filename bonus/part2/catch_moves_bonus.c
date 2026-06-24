/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 11:43:05 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	fixing_fichbowl(float ds, float angle, t_exec *exec)
{
	return (ft_abs((ds * cos(exec->ply.rotangle - angle))));
}

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_pixel(unsigned char *pixels, int o)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;

	r = pixels[o];
	g = pixels[o + 1];
	b = pixels[o + 2];
	a = pixels[o + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_the_walls22(int rx, t_exec *exec, float angle, t_ray *ray)
{
	static int	n;
	int			y;
	int			clg;

	y = 0;
	float wall_height = ((TILE_SIZE) / (ray->ds))
		* (((exec->info.win_wid / 2) / tan(degree_to_rad(AOV / 2))));
	if (isinf(wall_height))
	{
		wall_height = n;
		if (rx == 0)
			wall_height = exec->info.win_hei;
	}
	ray->wall_height = wall_height;
	n = ray->wall_height;
	ray->x = rx;
	clg = ((exec->info.win_hei) / 2) - (ray->wall_height / 2);
	while (y < clg)
		mlx_put_pixel(exec->wind_image, rx, y++, exec->info.clg_cl);
	draw_the_textures(exec, angle, &y, ray);
	while (y < (int)exec->info.win_hei)
		mlx_put_pixel(exec->wind_image, rx, y++, exec->info.flr_cl);
}

void	check_what_key_pressed(t_exec *exec, int *flg)
{
	if (mlx_is_key_down(exec->mlx, MLX_KEY_C))
	{
		if ((exec->ply.move_inc * 1.5) < 500)
			exec->ply.move_inc *= 1.5;
	}
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_Z))
	{
		if ((exec->ply.move_inc / 1.5) > 100)
			exec->ply.move_inc /= 1.5;
	}
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_RIGHT) && ++(*flg))
		move_right(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_LEFT) && ++(*flg))
		move_left(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_W) && ++(*flg))
		move_up(exec);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_S) && ++(*flg))
		move_down(exec);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_D) && ++(*flg))
		move_right(exec, 0);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_A) && ++(*flg))
		move_left(exec, 0);
	else if ((mlx_is_key_down(exec->mlx, MLX_KEY_ESCAPE))
		|| (mlx_is_key_down(exec->mlx, MLX_KEY_Q)))
		clean_and_exit(exec);
}
