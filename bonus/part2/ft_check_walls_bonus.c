/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:13:48 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/24 18:07:10 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	set_the_right_value(char ind, int *x, int *y, t_exec *e)
{
	if (ind == 0)
	{
		*x = e->ply.px - (cos(e->ply.rotangle - degree_to_rad(90)) * (e->i + 1));
		*y = e->ply.py - (sin(e->ply.rotangle - degree_to_rad(90)) * (e->i + 1));
	}
	else if (ind == 1)
	{
		*x = e->ply.px - (cos(e->ply.rotangle) * (e->i + 1));
		*y = e->ply.py - (sin(e->ply.rotangle) * (e->i + 1));
	}
	else if (ind == 2)
	{
		*x = e->ply.px - (cos(e->ply.rotangle + degree_to_rad(90)) * e->i);
		*y = e->ply.py - (sin(e->ply.rotangle + degree_to_rad(90)) * e->i);
	}
	else if (ind == 3)
	{
		*x = e->ply.px + (cos(e->ply.rotangle) * e->i);
		*y = e->ply.py + (sin(e->ply.rotangle) * e->i);
	}
}

// void adjust_increment(t_exec *exec, int i)
// {
// 	if (PIXELS % SPEED == 0)
// 		exec->ply.move_inc = i - 1;
// 	else
// 		exec->ply.move_inc = i - 2;
// }

void some_adjust_work(t_exec *exec,char ind)
{
	if (ind == 0)
		exec->ply.px++;
}

int	ft_check_walls(t_exec *exec, int ind)
{
	int	i;
	int	y;
	int	x;
	int	j;

	i = 0;
	j = 0;
	while (++i <= SPEED)
	{
		exec->i = i;
		set_the_right_value(ind, &x, &y, exec);
		if (i == 1 && exec->info.map[(int)floor(y / PIXELS)]
			[(int)floor(x / PIXELS)] == '1')
			return (0);
		else if (exec->info.map[(int)floor(y / PIXELS)]
			[(int)floor(x / PIXELS)] == '1')
			return (exec->ply.move_inc = i - 1, i);
	}
	exec->ply.move_inc = i - 1;
	return (i);
}
