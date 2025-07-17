/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:08:26 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/01 08:44:00 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	get_persent(float value, float new_v)
{
	return ((value / 100.0) * new_v);
}

float	adj_dimensions(t_exec *exec, int ind, int fl, int prs)
{
	int			x;
	int			y;
	float		dt;

	y = -1;
	while (exec->info.map[++y])
	{
		x = -1;
		while (exec->info.map[y][++x])
		{
			if (!one_of_these(exec->info.map[y][x]) && ++fl)
				break ;
		}
		if (fl)
			break ;
	}
	if (ind == 0)
	{
		x *= PIXELS;
		dt = exec->ply.px / 8.5 - x / 8.5;
		return (get_persent(dt, prs));
	}
	y *= PIXELS;
	dt = exec->ply.py / 8.5 - y / 8.5;
	return (get_persent(dt, prs));
}

void	fill_xstart_end(t_exec *exec, int *start, int *end, float diff)
{
	int	org_len;
	int	org_pos;

	org_len = exec->info.map_wid / PIXELS;
	org_pos = exec->ply.px / PIXELS;
	*start = org_pos - diff;
	*end = org_pos + (diff);
	if (*start < 0)
	{
		*end += *start * (-1);
		*start = 0;
	}
	else if (*end >= org_len)
	{
		*start -= (*end - org_len);
		*end = org_len;
	}
}

void	fill_ystart_end(t_exec *exec, int *start, int *end, float diff)
{
	int	org_len;
	int	org_pos;

	org_len = exec->info.map_hei / PIXELS;
	org_pos = exec->ply.py / PIXELS;
	*start = org_pos - diff;
	*end = org_pos + diff;
	if (*start < 0)
	{
		*end += *start * (-1);
		*start = 0;
	}
	else if (*end >= org_len)
	{
		*start -= (*end - org_len);
		*end = org_len;
	}
}
