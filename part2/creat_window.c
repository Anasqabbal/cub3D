/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:05:30 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 11:03:17 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../cub3d.h"

int creat_and_start_awindow(t_exec *exec)
{
    exec->mlx = mlx_init(exec->info.win_wid, exec->info.win_hei, "cub3D", true);
	if (!exec->mlx)
		return (printf("failed to init mlx\n"), -1);
	exec->wind_image = mlx_new_image(exec->mlx, exec->info.win_wid, exec->info.win_hei);
    if (!exec->wind_image)
    {
        printf("new image failed\n");
        /* free the init section for your mlx_init() */
        return (-1);
    }
	if (mlx_image_to_window(exec->mlx, exec->wind_image, 0, 0))
        return (printf("image to window failed\n"), -1);
    /* wind 2 */
    return (0);
}