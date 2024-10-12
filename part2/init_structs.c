/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:14:44 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 11:09:55 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int     init_info_struct(t_info *info, char **av)
{
    info->path = av[1];
    info->map = cub_get_map(info, 0);
    if (!info->map)
        return (printf("failed to get the map\n"), -1);
    info->win_wid = ft_strlen(info->map[0]) * PIXELS;
    info->flr_cl = 0xE3E3E3E3;
    info->clg_cl = 0x332d3133;
    return (0);
}

 int    init_structs(void *ptr, int ind, char **av)
 {
    t_exec *exec;

    (void)ind;
    exec = ptr;
    init_info_struct(&exec->info, av);
    return (0);
}