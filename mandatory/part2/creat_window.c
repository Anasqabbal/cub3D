/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:05:30 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/23 14:13:04 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	creat_and_start_awindow(t_exec *exec)
{
	exec->info.win_hei = 720;
	exec->info.win_wid = 1280;
	exec->mlx = mlx_init(exec->info.win_wid, exec->info.win_hei, "cub3D", true);
	if (!exec->mlx)
		return (-1);
	exec->wind_image = mlx_new_image(exec->mlx,
			exec->info.win_wid, exec->info.win_hei);
	if (!exec->wind_image)
		return (mlx_terminate(exec->mlx), -1);
	if (mlx_image_to_window(exec->mlx, exec->wind_image, 0, 0))
	{
		mlx_delete_image(exec->mlx, exec->wind_image);
		return (mlx_terminate(exec->mlx), -1);
	}
	return (0);
}
