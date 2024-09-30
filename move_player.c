/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:08:59 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/30 09:37:39 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int ft_move_player(t_exec *exec)
{
  t_cir cir;
  cir.cx = exec->tex.ply.px;
  cir.cy =  exec->tex.ply.py;
  cir.to_fill = 0;
  cir.rds = PIXELS / 6;
  if (cir.rds % 2 == 0)
    cir.rds -= 1;
  // draw_map(exec);
  // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px, exec->tex.ply.py);
  // draw_circle(exec, &cir);
  // ft_draw_rays(exec);
  return (0);
}