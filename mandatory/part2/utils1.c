/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:19:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/01 10:54:07 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	fixing_fichbowl(float ds, float angle, t_exec *exec)
{
	return (ft_abs((ds * cos(exec->ply.rotangle - angle))));
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
