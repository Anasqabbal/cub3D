/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:08:59 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/22 16:54:18 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int ft_move_player(t_exec *exec)
{
  t_cir cir;
  t_img img;
  img.xlen = PIXELS;
  img.ylen = PIXELS;
  img.color = 0xbbbbbb;
  cir.cx = exec->tex.ply.px;
  cir.cy =  exec->tex.ply.py;
  printf("(%d, %d)\n", cir.cx, cir.cy );
  img.image = mlx_new_image(exec->mlx.mlx, PIXELS, PIXELS);
  img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
  img.color = exec->inf.flr_cl;
  cir.to_fill = 0;
  cir.rds = PIXELS / 2;
  if (cir.rds % 2 == 0)
    cir.rds -= 1;
  exec->img = img;
  exec->img.color = 0xDB0000;
  // set_pixels_to_image(&img);
  // mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_w, exec->tex.flr.img, exec->tex.ply.px, exec->tex.ply.py);
  draw_circle(exec, &cir);
  printf("(%d, %d)\n", cir.cx, cir.cy );
  return (0);
}