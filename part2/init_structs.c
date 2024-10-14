/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:14:44 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/14 16:12:45 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int     init_info_struct(t_info *info, t_cub *cub, t_texture *text)
{
    info->map = text->map;
    info->win_wid = cub->len * PIXELS;
    info->win_hei = cub->len_h * PIXELS;
    info->flr_cl = 0x04ed93ff;
    info->clg_cl = 0x00190fff;
    return (0);
}

 int    init_structs(void *ptr, int ind, char **av)
 {
    t_exec *exec;

    (void)ind;
    exec = ptr;
    if (read_file(av, &exec->cub, &exec->text))
		  return (gc_free_all(), -1);
    init_info_struct(&exec->info, &exec->cub, &exec->text);
    return (0);
}