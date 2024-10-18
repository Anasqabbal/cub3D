/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_moves_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:18:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/18 17:19:35 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	clean_and_exit(void *ptr)
{
	t_exec	*exec;

	exec = ptr;
	gc_free_all();
	mlx_delete_image(exec->mlx, exec->wind_image);
	mlx_terminate(exec->mlx);
	exit (0);
}

void	move_left(t_exec *exec, char ind)
{
	if (ind == 0)
	{
		if (!ft_check_walls(exec, 0))
			return ;
		exec->ply.py -= (sin(exec->ply.rotangle
					- degree_to_rad(90)) * exec->ply.move_inc);
		exec->ply.px -= (cos(exec->ply.rotangle
					- degree_to_rad(90)) * exec->ply.move_inc);
	}
	else
	{
		exec->ply.rotangle -= VIEW_SPEED;
		if (exec->ply.rotangle < (float)0)
			exec->ply.rotangle += 2 * M_PI;
	}
}

void	move_up(t_exec *exec)
{
	if (!ft_check_walls(exec, 1))
		return ;
	exec->ply.py -= (sin(exec->ply.rotangle) * exec->ply.move_inc);
	exec->ply.px -= (cos(exec->ply.rotangle) * exec->ply.move_inc);
}

void	move_right(t_exec *exec, char ind)
{
	if (ind == 0)
	{
		if (!ft_check_walls(exec, 2))
			return ;
		exec->ply.py -= (sin(exec->ply.rotangle
					+ degree_to_rad(90)) * exec->ply.move_inc);
		exec->ply.px -= (cos(exec->ply.rotangle
					+ degree_to_rad(90)) * exec->ply.move_inc);
	}
	else
	{
		if (exec->ply.rotangle > (M_PI * 2))
			exec->ply.rotangle -= 2 * M_PI;
		exec->ply.rotangle += VIEW_SPEED;
	}
}

void	move_down(t_exec *exec)
{
	if (!ft_check_walls(exec, 3))
		return ;
	exec->ply.py += (sin(exec->ply.rotangle) * exec->ply.move_inc);
	exec->ply.px += (cos(exec->ply.rotangle) * exec->ply.move_inc);
}
