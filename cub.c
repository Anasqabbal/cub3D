/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/15 11:58:57 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int creat_and_start_awindow(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (-1);
	mlx->mlx_w = mlx_new_window(mlx->mlx, 1024, 400, "new cub3D");
    if (!mlx->mlx_w)
    {
        /* free the init section for your mlx_init() */
        return (-1);
    }
    mlx_loop(mlx->mlx);
}

int	main()
{
	t_mlx	mlx;

	if (creat_and_start_awindow(&mlx) < 0)
        return (1);
}