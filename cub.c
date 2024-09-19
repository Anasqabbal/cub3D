/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/19 16:21:00 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int creat_and_start_awindow(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (-1);
	mlx->mlx_w = mlx_new_window(mlx->mlx, mlx->win_wid, mlx->win_hei, "new cub3D");
    if (!mlx->mlx_w)
    {
        /* free the init section for your mlx_init() */
        return (-1);
    }
    mlx_loop(mlx->mlx);
    return (0);
}

int     init_info_struct(t_info *inf)
{
    inf->map = read_cub_get_map__(inf, 0);
    if (!inf->map)
        return (printf("failed to get the map\n"), -1);
    inf->wid = ft_strlen(inf->map[0]);
    printf("the width of some line is %d\n", inf->wid);
    return (0);
}

 int    init_structs(void *ptr, int ind, char **av)
 {
    t_exec *exec;

    if (ind == 0)
    {
        exec = ptr;
        exec->av = av;
        exec->inf.path = av[1];
        init_info_struct(&exec->inf);
        printf("your heegh is %u\n", exec->mlx.win_hei = exec->inf.hei);
        printf("your wid is %u\n", exec->mlx.win_wid = exec->inf.wid);
        exec->mlx.win_hei = exec->inf.hei * PIXELS;
        exec->mlx.win_wid = exec->inf.wid * PIXELS;
    }
    return (0);
 }

int start_cub(char **av)
{
    t_exec exec;

    init_structs(&exec, 0, av);
    creat_and_start_awindow(&exec.mlx);
    // draw_the_floor(&exec.mlx);
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (ft_putstr_fd("invalide argument\n", 2), 1);
    start_cub(av);
}