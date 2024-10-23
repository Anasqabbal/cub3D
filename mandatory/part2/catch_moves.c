/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/23 16:22:49 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	fixing_fichbowl(float ds, float angle, t_exec *exec)
{
	return (ft_abs((ds * cos(exec->ply.rotangle - angle))));
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_the_walls22(int rx, t_exec *exec, float angle, t_ray *ray)
{
    float wall_heigh;
    static int n;
    int y ;
    int x ;
    int color;

    wall_heigh = ((PIXELS) / (ray->ds)) * (((exec->info.map_wid / 2) / tan(degree_to_rad(AOV / 2)))); /* the new heigh of the wall that you want to draw */
    if (isinf(wall_heigh))
    {
        wall_heigh = n;
    }
    n = wall_heigh;
    y = 0;
    x = 0;
    int clg = ((exec->info.win_hei) / 2) - (wall_heigh / 2);
    while(y < clg)
        mlx_put_pixel(exec->wind_image, rx, y++, exec->info.clg_cl);
    int ofsetX;
    int o = 0;
    if (ray->hv == 1)
        ofsetX = (int)ray->dx % PIXELS;
    else
        ofsetX = (int)ray->dy % PIXELS;
    while((int)x++ < wall_heigh && x < (int)exec->info.win_hei)
    { 
        int top = y + (wall_heigh / 2) - (exec->info.map_hei / 2);
        int ofsetY = top * ((float)PIXELS / wall_heigh);
        o = ((PIXELS * ofsetY) + ofsetX) * 4;
        if (ray->hv == 0 && ((angle >= 0 && angle < M_PI_2) || (angle >= 3 * M_PI_2 && angle < 2 * M_PI)))
            color = (int)ft_pixel(exec->we->pixels[o], exec->we->pixels[o + 1], exec->we->pixels[o + 2], exec->we->pixels[o + 3]);
        else if (ray->hv == 0 && angle >= M_PI_2 && angle < 3 * M_PI_2)
            color = (int)ft_pixel(exec->ea->pixels[o], exec->ea->pixels[o + 1], exec->ea->pixels[o + 2], exec->ea->pixels[o + 3]);
        else if (ray->hv == 1 && angle >= 0 && angle < M_PI)
            color = (int)ft_pixel(exec->so->pixels[o], exec->so->pixels[o + 1], exec->so->pixels[o + 2], exec->so->pixels[o + 3]);
        else if (ray->hv == 1 && angle >= M_PI && angle < 2 * M_PI)
            color = (int)ft_pixel(exec->no->pixels[o], exec->no->pixels[o + 1], exec->no->pixels[o + 2], exec->no->pixels[o + 3]);
        mlx_put_pixel(exec->wind_image, rx, y++, color);
        
    }
    while(y < (int)exec->info.win_hei && y > x)
        mlx_put_pixel(exec->wind_image, rx, y++, exec->info.flr_cl);
    (void)exec;
}

void	catch_moves(void *p)
{
	t_exec	*exec;

	exec = p;
    if (mlx_is_key_down(exec->mlx, MLX_KEY_RIGHT))
		move_right(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_LEFT))
		move_left(exec, 1);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_W))
		move_up(exec);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_S))
		move_down(exec);
	else if (mlx_is_key_down(exec->mlx, MLX_KEY_D))
		move_right(exec, 0);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_A))
		move_left(exec, 0);
	else if (mlx_is_key_down(exec->mlx,  MLX_KEY_ESCAPE) || mlx_is_key_down(exec->mlx, MLX_KEY_Q))
		clean_and_exit(exec);
    ray_casting(exec);
}
