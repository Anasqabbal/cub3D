/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:14:44 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/03 10:16:41 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int     init_info_struct(t_info *inf, char **av)
{
    inf->path = av[1];
    inf->map = cub_get_map(inf, 0);
    if (!inf->map)
        return (printf("failed to get the map\n"), -1);
    inf->wid = ft_strlen(inf->map[0]);
    inf->flr_cl = 0xE3E3E3E3;
    // exec->inf.flr_cl= 0xFFFFFF;
    inf->clg_cl = 0x332d3133;
    return (0);
}
int init_mlx_struct(t_exec *exec)
{
    exec->mlxx.win_hei = exec->inf.hei * PIXELS;
    exec->mlxx.win_wid = (exec->inf.wid - 1) * PIXELS;
    return (0);
}

 int    init_structs(void *ptr, int ind, char **av)
 {
    t_exec *exec;

    exec = ptr;
    (void) ind;
    init_info_struct(&exec->inf, av);
    init_mlx_struct(exec);
    return (0);
}