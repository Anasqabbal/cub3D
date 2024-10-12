/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 14:53:48 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static int adjust_calculation(t_exec *exec)
// {
    
// }

// static void set_first_inter(float *cur_psy, float *cur_psy, float angle, t_exec *exec)
// {
    
// }

int find_horizontal_inter(float angle,t_exec *exec, t_ray *ray)
{
    float cur_psx;   
    float cur_psy;
    float xinc;
    float yinc;
    char     b;
    char     up;
    char     right;

    b = 0;
    xinc = PIXELS / tan(angle);
    yinc = PIXELS;
    fix_current_angle(&angle);
    it_is_up_or_down(angle, &up);
    it_is_left_or_right(angle, &right);
    cur_psy = floor(exec->tex.ply.py / PIXELS) * PIXELS;
    if (!up)
        cur_psy += (PIXELS);
    cur_psx = exec->tex.ply.px - ((exec->tex.ply.py - cur_psy) / tan(angle));
    if (up)
    {
        b = -1;
        yinc *= -1;
    }
    if (!right && xinc < 0)
        xinc *= -1;
    else if (right && xinc > 0)
        xinc *= -1;
    while(cur_psx > 0 && cur_psx < exec->info.win_wid && cur_psy > 0 && cur_psy < exec->info.win_hei)
    {
        if (exec->info.map[(int)floor(((cur_psy + b)/ PIXELS))][(int)floor(((cur_psx) / PIXELS))] == '1')
            break ;
           cur_psy += yinc;
           cur_psx += xinc;
    }
    ray->ds = (sqrt((pow((cur_psx - exec->tex.ply.px), 2)) + (pow((cur_psy - exec->tex.ply.py), 2))));
    ray->dx = cur_psx;
    ray->dy = cur_psy;
    return (ray->ds);
}

int find_vertical_inter(float angle, t_exec *exec, t_ray *ray)
{
    float  cur_psx;   
    float  cur_psy;
    float  yinc;
    float  xinc;
    char		up;
    char		right;
    char		b;

    fix_current_angle(&angle);
    it_is_up_or_down(angle, &up);
    it_is_left_or_right(angle, &right);
    b = 0;
    yinc = PIXELS * tan(angle);
	xinc = PIXELS;
    cur_psx = floor(exec->tex.ply.px / PIXELS) * PIXELS;
    if (!right)
		cur_psx += PIXELS;
    cur_psy = exec->tex.ply.py - ((exec->tex.ply.px - cur_psx) * tan(angle));
	if (up)
		yinc *= -1;
	if (right)
	{
		b = -1;
		xinc *= -1;
	}
	if (up && tan(angle) < 0)
		yinc *= -1;
	else if (!up && tan(angle) < 0)
		yinc *= -1;
    while(cur_psy > 0 && cur_psx > 0 && cur_psx < exec->info.win_wid && cur_psy < exec->info.win_hei)
    {
        if (exec->info.map[(int)floor(((cur_psy)/ PIXELS))][(int)floor(((cur_psx + b) / PIXELS))] == '1')
            break ; 
		cur_psx += xinc;
		cur_psy += yinc;
    }
    ray->ds = (sqrt((pow((cur_psx - exec->tex.ply.px), 2)) + (pow((cur_psy - exec->tex.ply.py), 2))));
    ray->dx = cur_psx;
    ray->dy = cur_psy;
    return (ray->ds);
}

int ray_casting(t_exec *exec)
{
    float  angle;
    float  i ;
    float  inc;
    t_ray ray[exec->info.win_wid];

    int     c;

    inc = exec->tex.ply.rays_inc;
    c = 0;
    i = 0;
    while((int)i <= (AOV) && c < (int)exec->info.win_wid)
    {
        angle = exec->tex.ply.rotangle - (degree_to_rad((AOV / 2) - i));
		fill_ray_information(exec, &ray[c], angle);
        if ((int)i == 30){
            exec->ray90.ds = ray[c].ds;
            exec->ray90.dx = ray[c].dx;
            exec->ray90.dy = ray[c].dy;
        }
        draw_the_walls22(c, exec, angle, &ray[c]);
        c++;
        i += inc;
    }
    return (0);
}
