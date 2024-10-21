/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:14:44 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/20 09:48:51 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_player_angle(t_exec *exec, char c)
{
	if (c == 'N')
	{
		exec->ply.rotangle = degree_to_rad(90);
	}
	else if (c == 'S')
		exec->ply.rotangle = degree_to_rad(270);
	else if (c == 'W')
		exec->ply.rotangle = degree_to_rad(180);
	else if (c == 'E')
		exec->ply.rotangle = degree_to_rad(0);

}

void	set_player_info(t_exec *exec)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (exec->info.map[y])
	{
		x = 0;
		while (exec->info.map[y][x])
		{
			if (!one_of_these(exec->info.map[y][x]))
			{
				exec->ply.rds = PIXELS / 6;
				exec->ply.px = (x * PIXELS) + (PIXELS / 2);
				exec->ply.py = (y * PIXELS) + (PIXELS / 2);
				exec->ply.rays = exec->info.map_wid;
				exec->ply.rays_inc = AOV / exec->ply.rays;
				exec->ply.move_inc = SPEED;
				set_player_angle(exec, exec->info.map[y][x]);
			}
			x++;
		}
		y++;
	}
}

int	init_info_struct(t_info *info, t_cub *cub, t_texture *text)
{
	info->map = text->map;
	info->map_wid = cub->len * PIXELS;
	info->map_hei = cub->len_h * PIXELS;
	info->flr_cl = 0x04ed93ff;
	info->clg_cl = 0x00190fff;
	return (0);
}

int	init_structs(void *ptr, char **av)
{
	t_exec	*exec;

	exec = ptr;
	if (read_file(av, &exec->cub, &exec->text))
		return (gc_free_all(), -1);
	init_info_struct(&exec->info, &exec->cub, &exec->text);
	return (0);
}
