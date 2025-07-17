/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/04 10:04:00 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	fix_hinc_status(float *xinc, float *yinc, float angle, float *py)
{
	char	up;
	char	right;

	*xinc = PIXELS / tan(angle);
	*yinc = PIXELS;
	it_is_up_or_down(angle, &up);
	it_is_left_or_right(angle, &right);
	if (!up)
		*py += (PIXELS);
	if (up)
		*yinc *= -1;
	if (!right && *xinc < 0)
		*xinc *= -1;
	else if (right && *xinc > 0)
		*xinc *= -1;
}

void	find_horizontal_inter(float angle, t_exec *exec, t_ray *ray, char b)
{
	float	cur_psx;
	float	cur_psy;
	float	xinc;
	float	yinc;

	fix_current_angle(&angle);
	cur_psy = floor(exec->ply.py / PIXELS) * PIXELS;
	fix_hinc_status(&xinc, &yinc, angle, &cur_psy);
	cur_psx = exec->ply.px - ((exec->ply.py - cur_psy) / tan(angle));
	if (yinc < 0)
		b = -1;
	while (cur_psx > 0 && cur_psx < exec->info.map_wid
		&& cur_psy > 0 && cur_psy < exec->info.map_hei)
	{
		if (!door_or_wall(ray, exec->info.map[(int)floor(((cur_psy + b)
							/ PIXELS))][(int)floor(((cur_psx) / PIXELS))]))
			break ;
		cur_psy += yinc;
		cur_psx += xinc;
	}
	ray->ds = (sqrt((pow((cur_psx - exec->ply.px), 2))
				+ (pow((cur_psy - exec->ply.py), 2))));
	ray->dx = cur_psx;
	ray->dy = cur_psy;
}

static void	fix_vinc_status(float *xinc, float *yinc, float angle, float *px)
{
	char	up;
	char	right;

	it_is_up_or_down(angle, &up);
	it_is_left_or_right(angle, &right);
	*yinc = PIXELS * tan(angle);
	*xinc = PIXELS;
	if (!right)
		*px += PIXELS;
	if (up)
		*yinc *= -1;
	if (right)
		*xinc *= -1;
	if (up && tan(angle) < 0)
		*yinc *= -1;
	else if (!up && tan(angle) < 0)
		*yinc *= -1;
}

void	find_vertical_inter(float angle, t_exec *exec, t_ray *ray, char b)
{
	float	cur_psx;
	float	cur_psy;
	float	yinc;
	float	xinc;

	fix_current_angle(&angle);
	cur_psx = floor(exec->ply.px / PIXELS) * PIXELS;
	fix_vinc_status(&xinc, &yinc, angle, &cur_psx);
	cur_psy = exec->ply.py - ((exec->ply.px - cur_psx) * tan(angle));
	if (xinc < 0)
		b = -1;
	while (cur_psy > 0 && cur_psx > 0 && cur_psx < exec->info.map_wid
		&& cur_psy < exec->info.map_hei)
	{
		if (!door_or_wall(ray, exec->info.map[(int)floor(((cur_psy) / PIXELS))]
				[(int)floor(((cur_psx + b) / PIXELS))]))
			break ;
		cur_psx += xinc;
		cur_psy += yinc;
	}
	ray->ds = (sqrt((pow((cur_psx - exec->ply.px), 2))
				+ (pow((cur_psy - exec->ply.py), 2))));
	ray->dx = cur_psx;
	ray->dy = cur_psy;
}

void	ray_casting(t_exec *exec)
{
	float			angle;
	float			i;
	float			inc;
	t_ray			ray[1];
	unsigned int	c;

	inc = exec->ply.rays_inc;
	c = 0;
	i = 0;
	while ((int)i <= (AOV) && c < exec->info.win_wid)
	{
		ray[0].d = 0;
		angle = exec->ply.rotangle - (degree_to_rad((AOV / 2) - i));
		fix_current_angle(&angle);
		fill_ray_information(exec, &ray[0], angle);
		draw_the_walls22(c, exec, angle, &ray[0]);
		c++;
		i += inc;
	}
}
