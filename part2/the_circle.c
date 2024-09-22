/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:43:13 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/22 16:35:23 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void fill_circle2(t_exec *exec, t_cir *cir, int ind, int fix)
{
	while (ind == 1 && cir->to_center != cir->cx)
	{
		mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, cir->to_center++, fix, exec->img.color);
	}
	while (ind == 2 && cir->to_center != cir->cx)
	{
		mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, cir->to_center--, fix, exec->img.color);
	}
	while (ind == 3 && cir->to_center != cir->cy)
	{
		mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, fix, cir->to_center++, exec->img.color);
	}
	while (ind == 4 && cir->to_center != cir->cy)
	{
		mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, fix, cir->to_center--, exec->img.color);
	}
}

static void	fill_circle(t_exec *exec, t_cir *cir, int ind, int fix)
{
	if (!cir->to_fill)
	{
		fill_circle2(exec, cir, ind, fix);
		return ;
	}
	while (ind == 1 && cir->to_center != cir->cx)
		*(int *)(exec->img.image_add
				+ ((cir->to_center++) * (exec->img.bits_pp / 8)
					+ ((fix) * exec->img.line_))) = exec->img.color;
	while (ind == 2 && cir->to_center != cir->cx)
		*(int *)(exec->img.image_add + ((cir->to_center--)
					* (exec->img.bits_pp / 8)
					+ ((fix) * exec->img.line_))) = exec->img.color;
	while (ind == 3 && cir->to_center != cir->cy)
		*(int *)(exec->img.image_add + ((fix) * (exec->img.bits_pp / 8)
					+ ((cir->to_center++) * exec->img.line_)))
			= exec->img.color;
	while (ind == 4 && cir->to_center != cir->cy)
		*(int *)(exec->img.image_add + ((fix) * (exec->img.bits_pp / 8)
					+ ((cir->to_center--) * exec->img.line_)))
			= exec->img.color;
}

static void	complete_fill(t_exec *exec, t_cir *cir)
{
	fill_circle(exec, cir, 3, cir->cx - cir->x);
	cir->to_center = cir->cx + cir->y;
	fill_circle(exec, cir, 2, cir->cy + cir->x);
	cir->to_center = cir->cy + cir->x;
	fill_circle(exec, cir, 4, cir->cx + cir->y);
	cir->to_center = cir->cx - cir->y;
	fill_circle(exec, cir, 1, cir->cy + cir->x);
	cir->to_center = cir->cy + cir->x;
	fill_circle(exec, cir, 4, cir->cx - cir->y);
	cir->to_center = cir->cx + cir->y;
	fill_circle(exec, cir, 2, cir->cy + cir->x);
	cir->to_center = cir->cy - cir->x;
	fill_circle(exec, cir, 3, cir->cx + cir->y);
	cir->to_center = cir->cx - cir->y;
	fill_circle(exec, cir, 1, cir->cy + cir->x);
	cir->to_center = cir->cy - cir->x;
	fill_circle(exec, cir, 3, cir->cx - cir->y);
}

static void	_circle_points_on_img(t_exec *exec, t_cir *cir)
{
	cir->to_center = cir->cx + cir->x;
	fill_circle(exec, cir, 2, cir->cy + cir->y);
	cir->to_center = cir->cy + cir->y;
	fill_circle(exec, cir, 4, cir->cx + cir->x);
	cir->to_center = cir->cx - cir->x;
	fill_circle(exec, cir, 1, cir->cy + cir->y);
	cir->to_center = cir->cy + cir->y;
	fill_circle(exec, cir, 4, cir->cx - cir->x);
	cir->to_center = cir->cx + cir->x;
	fill_circle(exec, cir, 2, cir->cy - cir->y);
	cir->to_center = cir->cy - cir->y;
	fill_circle(exec, cir, 3, cir->cx + cir->x);
	cir->to_center = cir->cx - cir->x;
	fill_circle(exec, cir, 1, cir->cy - cir->y);
	cir->to_center = cir->cy - cir->y;
	complete_fill(exec, cir);
}

void	draw_circle(t_exec *exec, t_cir *cir)
{
	int	d;

	cir->x = 0;
	cir->y = cir->rds;
	d = 1 - cir->y;
	_circle_points_on_img(exec, cir);
	while (cir->x < cir->y)
	{
		if (d < 0)
			d += 2 * cir->x + 3;
		else
		{
			d += 2 * (cir->x - cir->y) + 5;
			cir->y--;
		}
		cir->x++;
		_circle_points_on_img(exec, cir);
	}
}
