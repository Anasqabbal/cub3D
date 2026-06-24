/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:40 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 10:00:52 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_crosshair(t_exec *exec)
{
	int	i;
	int	count;

	i = 5;
	count = 0;
	while (count < 5)
	{
		mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2),
			(exec->info.win_hei / 2 + i), 0xff0000ff);
		mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2),
			(exec->info.win_hei / 2 - i), 0xff0000ff);
		mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2 + i),
			(exec->info.win_hei / 2), 0xff0000ff);
		mlx_put_pixel(exec->wind_image, (exec->info.win_wid / 2 - i),
			(exec->info.win_hei / 2), 0xff0000ff);
		i++;
		count++;
	}
}

void	mouse_movements(t_exec *exec, int *ms)
{
	mlx_get_mouse_pos(exec->mlx, &exec->ms.curx, &exec->ms.cury);
	if ((exec->ms.curx > 0 && exec->ms.curx < (int)exec->info.win_wid)
		&& (exec->ms.cury > 0 && exec->ms.cury < (int)exec->info.win_hei)
		&& ++(*ms))
	{
		mlx_set_mouse_pos(exec->mlx, exec->info.win_wid / 2,
			exec->info.win_hei / 2);
		mlx_set_cursor_mode(exec->mlx, MLX_MOUSE_HIDDEN);
		exec->ply.rotangle += ((exec->ms.curx - exec->ms.prevx)
				* exec->ms.sensitivity);
		fix_current_angle(&exec->ply.rotangle);
		mlx_get_mouse_pos(exec->mlx, &exec->ms.prevx, & exec->ms.prevy);
	}
	mlx_get_mouse_pos(exec->mlx, &exec->ms.prevx, & exec->ms.prevy);
}

void	reload_function(t_exec *exec, int *rld)
{
	static int	rld1;

	if (*rld == 4)
	{
		exec->wp.blt = 3;
		*rld = 0;
		return ;
	}
	draw_an_image(exec, exec->wp.rld[rld1++], 0, 0);
	if (rld1 == exec->wp.rldnb)
	{
		rld1 = 0;
		(*rld)++;
	}
}

void	weapon_animation(t_exec *exec, int *frm, int *rld)
{
	if (mlx_is_key_down(exec->mlx, MLX_KEY_T) || *frm)
	{
		if (exec->wp.blt || *frm)
		{
			draw_an_image(exec, exec->wp.sht[(*frm)++], 0, 4);
			if (*frm == exec->wp.shtnb)
			{
				*rld = 0;
				*frm = 0;
				exec->wp.blt--;
			}
			if (!exec->wp.blt)
				(*rld)++;
		}
	}
	else if ((*rld && !exec->wp.blt))
		reload_function(exec, rld);
	else
		draw_an_image(exec, exec->wp.hld, 0, 4);
}

void	mouse_fun(void *ptr)
{
	t_exec		*exec;
	static int	ms;
	static int	frm;
	static int	flg;
	static int	rld;

	exec = ptr;
	flg = 0;
	check_what_key_pressed(exec, &flg);
	mouse_movements(exec, &ms);
	if (flg || ms || exec->frst)
	{
		ray_casting(exec);
		weapon_animation(exec, &frm, &rld);
		draw_crosshair(exec);
		draw_mini_map(exec);
		flg = 0;
		ms = 0;
	}
	exec->frst = 0;
}
