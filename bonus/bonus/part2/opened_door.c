/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opened_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:25:18 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/06 09:33:53 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	in_vertical_inter(t_exec *exec, int *color, t_ray *ray)
{
	char	up;
	char	right;

	it_is_up_or_down(exec->ply.rotangle, &up);
	it_is_left_or_right(exec->ply.rotangle, &right);
	if (right && up && exec->info.old_map[(int)floor((ray->dy) / PIXELS)]
		[(int)floor((ray->dx) / PIXELS)] == 'D')
		*color = get_pixel(exec->odlr->pixels, ray->o);
	else if (!up && right && exec->info.old_map[(int)floor((ray->dy) / PIXELS)]
		[(int)floor((ray->dx) / PIXELS)] == 'D')
		*color = get_pixel(exec->odll->pixels, ray->o);
	else if (!right && up && exec->info.old_map[(int)floor((ray->dy) / PIXELS)]
		[(int)floor((ray->dx - 1) / PIXELS)] == 'D')
		*color = get_pixel(exec->odrr->pixels, ray->o);
	else if (!right && !up && exec->info.old_map[(int)floor((ray->dy) / PIXELS)]
		[(int)floor((ray->dx - 1) / PIXELS)] == 'D')
		*color = get_pixel(exec->odrl->pixels, ray->o);
}

static void	in_horiz_inter(t_exec *exec, int *color, t_ray *ray)
{
	char	up;
	char	right;

	it_is_up_or_down(exec->ply.rotangle, &up);
	it_is_left_or_right(exec->ply.rotangle, &right);
	if (right && up && exec->info.old_map[(int)floor((ray->dy) / PIXELS)]
		[(int)floor((ray->dx) / PIXELS)] == 'D')
		*color = get_pixel(exec->odlr->pixels, ray->o);
	else if (!up && right && exec->info.old_map[(int)floor((ray->dy - 1)
				/ PIXELS)][(int)floor((ray->dx) / PIXELS)] == 'D')
		*color = get_pixel(exec->odrr->pixels, ray->o);
	else if (!right && up && exec->info.old_map[(int)floor((ray->dy) / PIXELS)]
		[(int)floor((ray->dx) / PIXELS)] == 'D')
		*color = get_pixel(exec->odll->pixels, ray->o);
	else if (!right && !up && exec->info.old_map[(int)floor((ray->dy - 1)
				/ PIXELS)][(int)floor((ray->dx) / PIXELS)] == 'D')
		*color = get_pixel(exec->odrl->pixels, ray->o);
}

void	draw_opened_door(t_exec *exec, int *color, t_ray *ray)
{
	int	prev;

	prev = *color;
	if (ray->hv == 0)
		in_vertical_inter(exec, color, ray);
	else
		in_horiz_inter(exec, color, ray);
	if (*color == 0)
		*color = prev;
}
