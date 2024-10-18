/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/18 17:19:28 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	fixing_fichbowl(float ds, float angle, t_exec *exec)
{
	return (ft_abs((ds * cos(exec->ply.rotangle - angle))));
}

void	draw_the_walls22(int rx, t_exec *exec, float angle, t_ray *ray)
{
	float wall_heigh;
	static int n;
	int y ;
	int x ;
	int color;
	float no, e,w,s;


	wall_heigh  =((PIXELS) / (ray->ds)) * (((exec->info.win_wid / 2) / tan(degree_to_rad(AOV / 2))));
	if (isinf(wall_heigh))
		wall_heigh = n;
	n = wall_heigh;
	y = 0;
	x = 0;
	if (wall_heigh > exec->info.win_hei)
		wall_heigh = exec->info.win_hei;
	int clg = ((exec->info.win_hei) / 2) - (wall_heigh / 2);
		no = angle > 0 && angle < M_PI;
	s = !no;
	e = (angle < (0.5) * M_PI) || (angle > 1.5 * M_PI);
	w = !e;
	if (ray->hv == 0 && w)
		color = 0x015f3aff;
	else if (ray->hv == 0 && e)
		color = 0x015030ff;
	else if (ray->hv == 1 && no)
		color = 0x026e44ff;
	else if (ray->hv == 1 && s)
		color = 0x014126ff;
	while(y < clg)
		mlx_put_pixel(exec->wind_image, rx, y++,exec->info.clg_cl);
	while((int)x++ < wall_heigh && x < (int)exec->info.win_wid)
		mlx_put_pixel(exec->wind_image, rx, y++, color);
	while(y < (int)exec->info.win_hei)
		mlx_put_pixel(exec->wind_image, rx, y++, exec->info.flr_cl);
}

void	show_2dmap(t_exec *exec)
{
	draw_map(exec, PIXELS, 0);
	mlx_put_pixel(exec->wind_image, exec->ply.px, exec->ply.py, 0xf54242f5);
	mlx_put_pixel(exec->wind_image, exec->ply.px - 1, exec->ply.py, 0x5AFF055A);
	mlx_put_pixel(exec->wind_image, exec->ply.px + 1, exec->ply.py, 0x5AFF055A);
	mlx_put_pixel(exec->wind_image, exec->ply.px, exec->ply.py + 1, 0x5AFF055A);
	mlx_put_pixel(exec->wind_image, exec->ply.px, exec->ply.py - 1, 0x5AFF055A);
}

void	catch_moves(mlx_key_data_t key, void *p)
{
	t_exec	*exec;

	exec = p;
	if (key.key == MLX_KEY_RIGHT)
		move_right(exec, 1);
	else if (key.key == MLX_KEY_LEFT)
		move_left(exec, 1);
	else if (key.key == MLX_KEY_W)
		move_up(exec);
	else if (key.key == MLX_KEY_S)
		move_down(exec);
	else if (key.key == MLX_KEY_D)
		move_right(exec, 0);
	else if (key.key == MLX_KEY_A)
		move_left(exec, 0);
	else if (key.key == MLX_KEY_ESCAPE || key.key == MLX_KEY_Q)
		clean_and_exit(exec);
	ray_casting(exec);
	draw_mini_map(exec);
	if (key.key == MLX_KEY_E)
		show_2dmap(exec);
}
