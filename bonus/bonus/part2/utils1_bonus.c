/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:19:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/06 09:41:36 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	door_or_wall(t_ray *ray, char c)
{
	if (c == '1')
		return (0);
	else if (c == 'D')
	{
		if (ray)
			ray->d = 2;
		return (0);
	}
	return (1);
}

char	the_old_one(t_exec *exec, float oldy, float oldx)
{
	if (exec->info.old_map[(int)floor(oldy / PIXELS)]
		[(int)floor(oldx / PIXELS)] == 'D')
		return ('D');
	else
		return ('0');
}

void	clean_and_exit(void *ptr)
{
	t_exec	*exec;

	exec = ptr;
	gc_free_all();
	mlx_delete_image(exec->mlx, exec->wind_image);
	mlx_terminate(exec->mlx);
	exit (0);
}

int	one_of_these(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

float	degree_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}
