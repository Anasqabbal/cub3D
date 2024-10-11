/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:22:43 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/11 17:50:28 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


double fixing_fichbowl(double ds, double angle, t_exec *exec)
{
    // printf("the distance that your ray travels is %f and the new one is %d\n,", ds, ft_abs((int)(ds * cos(angle - exec->tex.ply.rotangle))));

    return (ft_abs((ds * cos(exec->tex.ply.rotangle - angle))));
}

void draw_the_walls22(int rx, t_exec *exec, double angle, t_ray *ray)
{
    double wall_heigh;
    static int n;
    int y ;
    int x ;
    int color;
    double no, e,w,s;

    
    wall_heigh  =((PIXELS) / (ray->ds)) * (((exec->mlxx.win_wid / 2) / tan(degree_to_rad(AOV / 2))));
    if (isinf(wall_heigh))
        wall_heigh = n;
    n = wall_heigh;
    y = 0;
    x = 0;
    if (wall_heigh > exec->mlxx.win_hei)
        wall_heigh = exec->mlxx.win_hei;
    int clg = ((exec->mlxx.win_hei) / 2) - (wall_heigh / 2);

      no = angle > 0 && angle < M_PI;
    s = !no;
    e = (angle < (0.5) * M_PI) || (angle > 1.5 * M_PI);
    w = !e;
    if (ray->hv == 0 && w)
        color = 0xE9FF97;
    else if (ray->hv == 0 && e)
        color = 0xFFD18E;
    else if (ray->hv == 1 && no)
        color = 0xFFA38F;
    else if (ray->hv == 1 && s)
        color = 0xFF7EE2;
    while(y < clg)
        mlx_put_pixel(exec->wind_image, rx, y++,exec->inf.clg_cl);
    while((int)x++ < wall_heigh && x < (int)exec->mlxx.win_wid)
        mlx_put_pixel(exec->wind_image, rx, y++, color);
    while(y < (int)exec->mlxx.win_hei)
        mlx_put_pixel(exec->wind_image, rx, y++, exec->inf.flr_cl);
    (void)exec;
}

int move_left(t_exec *exec)
{
    if (!ft_check_walls(exec, 0))
        return (0);
    exec->tex.ply.py -= (sin(exec->tex.ply.rotangle - degree_to_rad(90)) * exec->tex.ply.move_inc);
    exec->tex.ply.px -= (cos(exec->tex.ply.rotangle - degree_to_rad(90)) * exec->tex.ply.move_inc);
    return (0);
}

int     move_up(t_exec *exec)
{
    if (!ft_check_walls(exec, 1))
        return (0);
    exec->tex.ply.py -= (sin(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
    exec->tex.ply.px -= (cos(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
    return (0);
}

int move_right(t_exec *exec)
{
    if (!ft_check_walls(exec, 2))
        return (0);
    exec->tex.ply.py -= (sin(exec->tex.ply.rotangle + degree_to_rad(90)) * exec->tex.ply.move_inc);
    exec->tex.ply.px -= (cos(exec->tex.ply.rotangle + degree_to_rad(90)) * exec->tex.ply.move_inc);
    return (0);
}

int move_down(t_exec *exec)
{
    if (!ft_check_walls(exec, 3))
        return (0);
    exec->tex.ply.py += (sin(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
    exec->tex.ply.px += (cos(exec->tex.ply.rotangle) * exec->tex.ply.move_inc);
    return (0);
}



int look_righ(t_exec *exec)
{
    if (exec->tex.ply.rotangle > (M_PI * 2))
        exec->tex.ply.rotangle -= 2 * M_PI;
    exec->tex.ply.rotangle += VIEW_SPEED;
    return (0);
}

int look_left(t_exec *exec)
{
    exec->tex.ply.rotangle -= VIEW_SPEED;
    if (exec->tex.ply.rotangle < (double)0)
        exec->tex.ply.rotangle += 2 * M_PI;
     return (0);
}

void catch_moves(mlx_key_data_t key, void *p)
{
    t_exec *exec;

    exec = p;
    if (key.key == MLX_KEY_RIGHT)
        look_righ(exec);
    else if (key.key == MLX_KEY_LEFT)
        look_left(exec);
    else if (key.key == MLX_KEY_W)
        move_up(exec);
    else if (key.key == MLX_KEY_S)
        move_down(exec);
    else if (key.key == MLX_KEY_D)
        move_right(exec);
    else if (key.key == MLX_KEY_A)
        move_left(exec);
    ft_move_player(exec);// to destroy 2d map
    ray_casting(exec);
    if (key.key == MLX_KEY_E)
    {
        draw_map(exec);
        bresenham_line_algo2(exec->tex.ply.py, exec->tex.ply.px, exec->ray90.dy, exec->ray90.dx, exec);
        mlx_put_pixel(exec->wind_image, exec->tex.ply.px, exec->tex.ply.py, 0xf54242f5);
        mlx_put_pixel(exec->wind_image, exec->tex.ply.px - 1, exec->tex.ply.py, 0x5AFF055A);
        mlx_put_pixel(exec->wind_image, exec->tex.ply.px + 1, exec->tex.ply.py, 0x5AFF055A);
        mlx_put_pixel(exec->wind_image, exec->tex.ply.px, exec->tex.ply.py + 1, 0x5AFF055A);
        mlx_put_pixel(exec->wind_image, exec->tex.ply.px, exec->tex.ply.py - 1, 0x5AFF055A);
    }
}