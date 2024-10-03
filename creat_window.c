/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:05:30 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/03 10:33:09 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"cub3d.h"

int creat_and_start_awindow(t_exec *exec)
{
    // mlx->mlx = mlx_init();
	// if (!mlx->mlx)
	// 	return (-1);
	// mlx->mlx_w = mlx_new_window(mlx->mlx, mlx->win_wid, mlx->win_hei, "new cub3D");
    //     if (!mlx->mlx_w)
    // {
    //     /* free the init section for your mlx_init() */
    //     return (-1);
    // }
	// mlx->mlx_w1 = mlx_new_window(mlx->mlx, mlx->win_wid, mlx->win_hei, "render");

    exec->mlx = mlx_init(exec->mlxx.win_wid, exec->mlxx.win_hei, "cub3D", true);
	if (!exec->mlx)
		return (printf("failed to init mlx\n"), -1);
	exec->wind_image = mlx_new_image(exec->mlx, exec->mlxx.win_wid, exec->mlxx.win_hei);
    if (!exec->wind_image)
    {
        printf("new image failed\n");
        /* free the init section for your mlx_init() */
        return (-1);
    }
	if (mlx_image_to_window(exec->mlx, exec->wind_image, 0, 0))
        return (printf("image to window failed\n"), -1);
    return (0);
}