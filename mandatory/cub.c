/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/19 15:42:36 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t *ft_texture(t_exec *exec, char *path_texture)
{
    mlx_texture_t *texture;
    mlx_image_t *image;
    texture = mlx_load_png(path_texture);
    if (!texture)
	{
		write(2,"Error\nIn valid path",19);
		printf("'%s'", path_texture);
		clean_and_exit(exec);
	}
    image = mlx_texture_to_image(exec->mlx, texture);
	mlx_delete_texture(texture);
    return image;
}

int	start_cub(char **av)
{
	t_exec	exec;

	if (init_structs(&exec, av) < 0)
		return (-1);
	if (creat_and_start_awindow(&exec) < 0)
		return (gc_free_all(), -1);
	draw_map(&exec, PIXELS, 0);
    exec.no = ft_texture(&exec, exec.text.NO);
    exec.so = ft_texture(&exec, exec.text.SO);
    exec.we = ft_texture(&exec, exec.text.WE);
    exec.ea = ft_texture(&exec, exec.text.EA);
    exec.d = ft_texture(&exec, "./png/door.png");
	set_player_info(&exec);
	ray_casting(&exec);
	mlx_key_hook(exec.mlx, &catch_moves, &exec);
	mlx_close_hook(exec.mlx, clean_and_exit, &exec);
	mlx_loop(exec.mlx);
	mlx_terminate(exec.mlx);
	return (0);
}

int	check_extention(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u'
		|| str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || ac > 3)
		return (write(0, "error\ninvalid argument\n", 23), 1);
	if (check_extention(av[1]))
		return (write(0, "error\ninvalid extention\n", 24), 1);
	if (start_cub(av) < 0)
		return (1);
}
