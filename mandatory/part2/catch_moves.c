/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/20 09:47:16 by anqabbal         ###   ########.fr       */
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
    double wall_heigh;
    static int n;
    int y ;
    int x ;
    int color;
    // int no, e,w,s;
    
    // (void)angle;
    // ray->ds = fixing_fichbowl(ray->ds, angle , exec);
    wall_heigh = ((PIXELS) / (ray->ds)) * (((exec->info.map_wid / 2) / tan(degree_to_rad(AOV / 2)))); /* the new heigh of the wall that you want to draw */
    if (isinf(wall_heigh))
        wall_heigh = n;
    n = wall_heigh;
    y = 0;
    x = 0;
    int clg = ((exec->info.map_hei) / 2) - (wall_heigh / 2);
    // no = angle > 0 && angle < M_PI;
    // s = !no;
    // e = (angle < (0.5) * M_PI) || (angle > 1.5 * M_PI);
    // w = !e;

    while(y < clg)
        mlx_put_pixel(exec->wind_image, rx, y++, exec->info.clg_cl);
    int ofsetX;
    int o = 0;
    if (ray->hv == 1)
        ofsetX = (int)ray->dx % PIXELS;
    else
        ofsetX = (int)ray->dy % PIXELS;
    while((int)x++ < wall_heigh && x < (int)exec->info.map_hei)
    { 
        int top = y + (wall_heigh / 2) - (exec->info.map_hei / 2);
        int ofsetY = top * ((double)PIXELS / wall_heigh);
        o = ((PIXELS * ofsetY) + ofsetX) * 4;
        // if (ray->d == 2)
        // {
        //     color = (int)ft_pixel(exec->d->pixels[o], exec->d->pixels[o + 1], exec->d->pixels[o + 2], exec->d->pixels[o + 3]);
        //     // printf("==> %c\n", exec->info.map[(int)floor(ray->dy / PIXELS)][(int)floor(ray->dx / PIXELS)]);
        //     mlx_put_pixel(exec->wind_image, rx, y++, color);
        // }
        if (ray->hv == 0 && ((angle >= 0 && angle < M_PI_2) || (angle >= 3 * M_PI_2 && angle < 2 * M_PI)))
            color = (int)ft_pixel(exec->we->pixels[o], exec->we->pixels[o + 1], exec->we->pixels[o + 2], exec->we->pixels[o + 3]);
        else if (ray->hv == 0 && angle >= M_PI_2 && angle < 3 * M_PI_2)
            color = (int)ft_pixel(exec->ea->pixels[o], exec->ea->pixels[o + 1], exec->ea->pixels[o + 2], exec->ea->pixels[o + 3]);
        else if (ray->hv == 1 && angle >= 0 && angle < M_PI)
            color = (int)ft_pixel(exec->so->pixels[o], exec->so->pixels[o + 1], exec->so->pixels[o + 2], exec->so->pixels[o + 3]);
        else if (ray->hv == 1 && angle >= M_PI && angle < 2 * M_PI)
            color = (int)ft_pixel(exec->no->pixels[o], exec->no->pixels[o + 1], exec->no->pixels[o + 2], exec->no->pixels[o + 3]);
        // if (ray->hv)
        //     color = 0xff0000ff;
        // else
        //     color = 0x00ff00ff;
        mlx_put_pixel(exec->wind_image, rx, y++, color);
        
    }
    while(y < (int)exec->info.map_hei && y > x)
        mlx_put_pixel(exec->wind_image, rx, y++, exec->info.flr_cl);
    (void)exec;
}

void	show_2dmap(t_exec *exec)
{
	draw_map(exec, PIXELS, 0);
	mlx_put_pixel(exec->wind_image, exec->ply.px, exec->ply.py, 0xf54242f5);
	mlx_put_pixel(exec->wind_image, exec->ply.px - 1, exec->ply.py, 0x5AFF055A);
	mlx_put_pixel(exec->wind_image, exec->ply.px + 1, exec->ply.py, 0x5AFF055A);
	mlx_put_pixel(exec->wind_image, exec->ply.px, exec->ply.py + 1, 0x5AFF055A);
	mlx_put_pixel(exec->wind_image, exec->ply.px, exec->ply.py - 1, 0x5AFF055A);
}

void	catch_moves(mlx_key_data_t key, void *p)
{
	t_exec	*exec;

	exec = p;
	if (key.key == MLX_KEY_RIGHT)
		move_right(exec, 1);
	else if (key.key == MLX_KEY_LEFT)
		move_left(exec, 1);
	else if (key.key == MLX_KEY_W)
		move_up(exec);
	else if (key.key == MLX_KEY_S)
		move_down(exec);
	else if (key.key == MLX_KEY_D)
		move_right(exec, 0);
	else if (key.key == MLX_KEY_A)
		move_left(exec, 0);
	else if (key.key == MLX_KEY_ESCAPE || key.key == MLX_KEY_Q)
		clean_and_exit(exec);
	ray_casting(exec);
	if (key.key == MLX_KEY_E)
		show_2dmap(exec);
}
