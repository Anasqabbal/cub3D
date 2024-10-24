/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:24:24 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/24 11:00:23 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void to_bresenhams(t_exec *exec, t_ray *ray)
{
	exec->brs.ds = ray->ds;
	exec->brs.hv = ray->hv;
	exec->brs.dx = ray->dx;
	exec->brs.dy = ray->dy;
}

void	fill_ray_information(t_exec *exec, t_ray *ray, float angle)
{
	t_ray	rays[2];

	find_horizontal_inter(angle, exec, &rays[0], 0);
	find_vertical_inter(angle, exec, &rays[1], 0);
	rays[0].ds = fixing_fichbowl(rays[0].ds, angle, exec);
	rays[1].ds = fixing_fichbowl(rays[1].ds, angle, exec);
	if ((rays[0].ds < rays[1].ds && rays[0].ds != (INT_MIN))
		|| rays[1].ds == (INT_MIN))
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
	to_bresenhams(exec, ray);
}

void	it_is_left_or_right(float angle, char *value)
{
	if (angle < degree_to_rad(90) || angle > degree_to_rad(270))
		*value = 1;
	else
		*value = 0;
}

void	fix_current_angle(float *angle)
{
	if (*angle > (M_PI * 2))
		*angle -= 2 * M_PI;
	else if (*angle < (float)0)
		*angle += 2 * M_PI;
}

float	ft_abs(float nm)
{
	if (nm < 0)
		return (nm *= -1);
	else
		return (nm);
}

void	it_is_up_or_down(float angle, char *value)
{
	if (angle > degree_to_rad(0) && angle < degree_to_rad(180))
		*value = 1;
	else
		*value = 0;
}
