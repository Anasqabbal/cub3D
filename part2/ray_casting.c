/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/11 17:49:16 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"




void it_is_left_or_right(double angle, char *value)
{
    if (angle < degree_to_rad(90) || angle > degree_to_rad(270))
        *value = 1;
    else
        *value = 0;
}

void fix_current_angle(double *angle)
{
    if (*angle > (M_PI * 2))
        *angle -= 2 * M_PI;
    else if (*angle < (double)0)
        *angle += 2 * M_PI;
}

double ft_abs(double nm)
{
    if (nm < 0)
        return (nm *= -1);
    else
        return (nm);
}
void it_is_up_or_down(double angle, char *value)
{
    if (angle > degree_to_rad(0) && angle < degree_to_rad(180))
        *value = 1;
    else
        *value = 0;
}

int find_horizontal_inter(double angle,t_exec *exec, t_ray *ray)
{
    double cur_psx;   
    double cur_psy;
    double xinc;
    double yinc;
    char     b;
    char     up_angle;
    char    right_angle;
    (void)ray;



/*NOTE 

you are inside the tan(&) observation there is a probleme tan returns -1 
when the values is between 0 and 180 and decrement happens instead increment


*/
    b = 0;
    /* fix current angle*/
    fix_current_angle(&angle);
    it_is_up_or_down(angle, &up_angle);
    it_is_left_or_right(angle, &right_angle);

    /* find your ray is up or down right or left */
    xinc = PIXELS / tan(angle);
    yinc = PIXELS;
    
    mlx_put_pixel(exec->wind_image, exec->tex.ply.px, exec->tex.ply.py, 0x00000000);
	
   /* first step find the closet x and y coordinate */
    cur_psy = floor(exec->tex.ply.py / PIXELS) * PIXELS;
    if (!up_angle)
        cur_psy += (PIXELS);
    cur_psx = exec->tex.ply.px - ((exec->tex.ply.py - cur_psy) / tan(angle));
    

	/* decide the increment state POS or NEG */
    if (up_angle)
    {
        b = -1;
        yinc *= -1;
    }
    if (!right_angle && xinc < 0)
        xinc *= -1;
    else if (right_angle && xinc > 0)
        xinc *= -1;
    
    /* the while loop */
    while(cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy > 0 && cur_psy < exec->mlxx.win_hei)
    {
        // mlx_put_pixel(exec->wind_image, cur_psx, cur_psy, 0xfc0307fc);
        if (exec->inf.map[(int)floor(((cur_psy + b)/ PIXELS))][(int)floor(((cur_psx) / PIXELS))] == '1')
            break ;
           cur_psy += yinc;
           cur_psx += xinc;
    }
    ray->ds = (sqrt((pow((cur_psx - exec->tex.ply.px), 2)) + (pow((cur_psy - exec->tex.ply.py), 2))));
    ray->dx = cur_psx;
    ray->dy = cur_psy;
    return (ray->ds);
}

int find_vertical_inter(double angle, t_exec *exec, t_ray *ray)
{
    double  cur_psx;   
    double  cur_psy;
    double  yinc;
    double  xinc;
    char		up;
    char		right;
    char		b;

	(void)ray;
	/* fix angle and state view of your ray */
    fix_current_angle(&angle);
    it_is_up_or_down(angle, &up);
    it_is_left_or_right(angle, &right);

    b = 0;
    yinc = PIXELS * tan(angle);
	xinc = PIXELS;

	/* SET the closest x and y coordinate  */
    cur_psx = floor(exec->tex.ply.px / PIXELS) * PIXELS;
    if (!right)
		cur_psx += PIXELS;
    cur_psy = exec->tex.ply.py - ((exec->tex.ply.px - cur_psx) * tan(angle));
	
		
	/* DECIDE state of inc selon the state of tan(&) POS or NEG */
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

	/* while loop */
    while(cur_psy > 0 && cur_psx > 0 && cur_psx < exec->mlxx.win_wid && cur_psy < exec->mlxx.win_hei)
    {
    		// mlx_put_pixel(exec->wind_image, cur_psx, cur_psy, 0xf71302f7); /* to draw ray  on screen */
        if (exec->inf.map[(int)floor(((cur_psy)/ PIXELS))][(int)floor(((cur_psx + b) / PIXELS))] == '1')
            break ; 
		cur_psx += xinc;
		cur_psy += yinc;
    }
    ray->ds = (sqrt((pow((cur_psx - exec->tex.ply.px), 2)) + (pow((cur_psy - exec->tex.ply.py), 2))));
    ray->dx = cur_psx;
    ray->dy = cur_psy;
    return (ray->ds);
}

void fill_ray_information(t_exec *exec, t_ray *ray, double angle)
{
	t_ray	rays[2];

	find_horizontal_inter(angle, exec, &rays[0]);
	find_vertical_inter(angle, exec, &rays[1]);
	
	/*fixing fishingbowl first*/
	rays[0].ds = fixing_fichbowl(rays[0].ds, angle, exec);
	rays[1].ds = fixing_fichbowl(rays[1].ds, angle, exec);
	
	/* draw with bresenham's algo the rays */
	if ((rays[0].ds < rays[1].ds && rays[0].ds != (INT_MIN)) || rays[1].ds == (INT_MIN))
	{
		ray->dx = rays[0].dx;
		ray->dy = rays[0].dy;
		ray->ds = rays[0].ds;
		ray->hv = 1;
	}
	else
	{
		ray->dx = rays[1].dx;
		ray->dy = rays[1].dy;
		ray->ds = rays[1].ds;
		ray->hv = 0;
	}
}

int ray_casting(t_exec *exec)
{
    double  angle;
    double  i ;
    double  inc;
    t_ray ray[exec->mlxx.win_wid];

    int     c;

    inc = exec->tex.ply.rays_inc;
    c = 0;
    i = 0;
    while((int)i <= (AOV) && c < (int)exec->mlxx.win_wid)
    {
        angle = exec->tex.ply.rotangle - (degree_to_rad((AOV / 2) - i));
		fill_ray_information(exec, &ray[c], angle);
		// bresenham_line_algo2(exec->tex.ply.py, exec->tex.ply.px, ray[c].dy, ray[c].dx, exec);
        if ((int)i == 30){
            exec->ray90.ds = ray[c].ds;
            exec->ray90.dx = ray[c].dx;
            exec->ray90.dy = ray[c].dy;
        }
        draw_the_walls22(c, exec, angle, &ray[c]);
        // if (((dsh < dsv) && dsh != (INT_MIN)) || dsv == (INT_MIN))
        //     bresenham_line_algo2((int)exec->tex.ply.py, (int)exec->tex.ply.px, (int)ray[0].dy, (int)ray[0].dx, exec);
        // else
        //     bresenham_line_algo2((int)exec->tex.ply.py, (int)exec->tex.ply.px , (int)ray[1].dy, (int)ray[1].dx, exec);
        // if ((int) i == 30)
        // {
        //     ray90[0] = ray[0];
        //     ray90[1] = ray[1];
        // }
        // else
        c++;
        i += inc;
    }
    // exec->ray[0] = ray90[0];
    // exec->ray[1] = ray90[1];
    return (0);
}
