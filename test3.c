/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:22:13 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/27 17:56:34 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int too_free(char **res)
{
    int i = -1;
    while(res[++i])
        free(res[i]);
    free(res);
    return (0);
}

int main()
{
    /* creat map */
    int h_len = 10;
    char *wall = "1111111111111111111111111111111111111";
    int wid_len = ft_strlen(wall);
    char *flr = "1000000000000000000000000000000000001";
    char **map = malloc(sizeof(char *) * (h_len + 1));
    map[h_len] = NULL;
    int i = -1;
    while(++i < h_len)
    {
        if (i == 0 || i == h_len - 1)
            map[i] = ft_strdup(wall);
        else
            map[i] = ft_strdup(flr);
    }





    /* creat a window and textures */
    t_mlx m;

    m.mlx = mlx_init(m);
    m.mlx_w = mlx_new_window(m.mlx, wid_len * PIXELS, h_len * PIXELS, "just to understand things well");
    double y = h_len / 2;
    double x = wid_len / 2;

    // mlx_pixel_put(m.mlx, m.mlx_w, (x * PIXELS) + 1, (y * PIXELS), 0xFF0000);
    // mlx_pixel_put(m.mlx, m.mlx_w, (x * PIXELS) - 1, (y * PIXELS), 0xFF0000);
    // mlx_pixel_put(m.mlx, m.mlx_w, (x * PIXELS), (y * PIXELS) + 1, 0xFF0000);
    // mlx_pixel_put(m.mlx, m.mlx_w, (x * PIXELS), (y * PIXELS) - 1, 0xFF0000);
    mlx_pixel_put(m.mlx, m.mlx_w, (int)(x * PIXELS), (int)(y * PIXELS), 0xFF0000);
    printf("the value of y %f x = %f\n", y * PIXELS, x * PIXELS);
    i = 0;
    while(i < 10)
    {
        x = (cos((degree_to_rad(30)) * 1) + ((wid_len / 2) * 30) + i);
        y = (sin((degree_to_rad(30)) * 1) + ((h_len / 2) * 30) + i);
        mlx_pixel_put(m.mlx, m.mlx_w, (int)(x), (int)(y), 0xFF0000);
        i++;
    }
    printf("the value of y %f x = %f\n", y, x);
    mlx_loop(m.mlx);


    
    too_free(map);
}