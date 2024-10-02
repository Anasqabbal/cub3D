/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:08:59 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/02 17:34:49 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int ft_move_player(t_exec *exec)
{
  t_cir cir;
  cir.cx = exec->tex.ply.px;
  cir.cy =  exec->tex.ply.py;
  cir.to_fill = 0;
  cir.rds = exec->tex.ply.rds;
  if (cir.rds % 2 == 0)
    cir.rds -= 1;
  draw_map(exec);
  draw_circle(exec, &cir);
  return (0);
}