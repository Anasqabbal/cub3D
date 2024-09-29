/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:05:30 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/29 15:34:03 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"cub3d.h"

int creat_and_start_awindow(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (-1);
	mlx->mlx_w = mlx_new_window(mlx->mlx, mlx->win_wid, mlx->win_hei, "new cub3D");
    if (!mlx->mlx_w)
    {
        /* free the init section for your mlx_init() */
        return (-1);
    }
	mlx->mlx_w1 = mlx_new_window(mlx->mlx, mlx->win_wid, mlx->win_hei, "render");
    return (0);
}