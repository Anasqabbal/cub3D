/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:05:30 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 10:01:03 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	set_image_to_righ_place(t_exec *exec, mlx_image_t **hld, char ind)
{
	if (ind == 0)
		exec->wp.hld = *hld;
	else if (ind == 1)
		exec->wp.sht = hld;
	else
		exec->wp.rld = hld;
}

void	read_images(t_exec *exec, char ind, char *name, int frmnb)
{
	char		*src;
	char		*tmp;
	mlx_image_t	**hld;
	int			i;

	i = -1;
	hld = gc_malloc(sizeof(mlx_image_t *) * frmnb);
	if (!hld)
		return ;
	while (++i < frmnb)
	{
		tmp = ft_itoa(i);
		if (!tmp)
			clean_and_exit(exec);
		src = ft_strjoin(name, tmp);
		if (!src)
			clean_and_exit(exec);
		src = ft_strjoin(src, ".png");
		if (!src)
			clean_and_exit(exec);
		hld[i] = ft_texutre11(exec, src);
	}
	set_image_to_righ_place(exec, hld, ind);
}

int	creat_and_start_awindow(t_exec *exec)
{
	exec->info.win_hei = 720;
	exec->info.win_wid = 1280;
	exec->mlx = mlx_init(exec->info.win_wid, exec->info.win_hei, "cub3D", true);
	if (!exec->mlx)
		return (-1);
	exec->wind_image = mlx_new_image(exec->mlx,
			exec->info.win_wid, exec->info.win_hei);
	if (!exec->wind_image)
		return (mlx_terminate(exec->mlx), -1);
	if (mlx_image_to_window(exec->mlx, exec->wind_image, 0, 0))
	{
		mlx_delete_image(exec->mlx, exec->wind_image);
		return (mlx_terminate(exec->mlx), -1);
	}
	return (0);
}
