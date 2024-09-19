/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/19 18:00:33 by anqabbal         ###   ########.fr       */
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
    return (0);
}

int     init_info_struct(t_info *inf)
{
    inf->map = cub_get_map(inf, 0);
    if (!inf->map)
        return (printf("failed to get the map\n"), -1);
    inf->wid = ft_strlen(inf->map[0]);
    printf("the width of some line is %d\n", inf->wid);
    return (0);
}

void *fill_image_with_color(unsigned int len1, unsigned int len2, t_exec *exec)
{
    unsigned int x;
    unsigned int y;
    void    *image;
    void    *image_add;
    int     bits_p_p;
    int     line_;
    int     endian;
    
    image = mlx_new_image(exec->mlx.mlx, len1, len2);
    image_add = mlx_get_data_addr(image, &bits_p_p, &line_, &endian);
    x = -1;
    y = -1;
    while (++y < len1)
    {
        x = -1;
        while(++x < len2)
            ;
    }
    return (0);
}

int draw_the_floor(t_exec *exec)
{
    unsigned int  i;
    unsigned int  j;
    unsigned int   full_len = (exec->inf.hei * PIXELS * 2);
    unsigned int   full_len1 = (exec->inf.wid * (PIXELS));

    fill_image_with_color(full_len, full_len1, exec);
    i = -1;
    while(++i < full_len)
    {
        j = -1;
        while(++j < full_len1)
            mlx_pixel_put(exec->mlx.mlx, exec->mlx.mlx_w, i, j, exec->inf.flr_cl);
    }
    printf("the value of i == %u, and the value of %u\n", i, full_len1);
    printf("the value of j == %u, and the value of %u \n", j,  (exec->inf.wid * PIXELS));
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
        exec->inf.flr_cl = 0xbbbbbb;
        exec->inf.clg_cl = 0x332d31;
    }
    return (0);
}

int start_cub(char **av)
{
    t_exec exec;

    init_structs(&exec, 0, av);
    creat_and_start_awindow(&exec.mlx);
    printf("here\n");
    draw_the_floor(&exec);
    mlx_loop(exec.mlx.mlx);
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (ft_putstr_fd("invalide argument\n", 2), 1);
    start_cub(av);
}