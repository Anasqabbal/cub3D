/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:08:59 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/21 15:25:35 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int ft_move_player(t_exec *exec)
{
    (void)exec;
    // if (exec->tex.ply.endrx == 0 && exec->tex.)
    mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.ply.img, exec->tex.ply.px,  exec->tex.ply.py);
    return (0);
}