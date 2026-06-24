/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:23:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 11:31:57 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*ft_texutre11(t_exec *exec, char *path_texture)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path_texture);
	if (!texture)
	{
		write(2, "Error\ninvalid path", 19);
		ft_putendl_fd(path_texture, 2);
		clean_and_exit(exec);
	}
	image = mlx_texture_to_image(exec->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

int	start_cub(char **av)
{
	t_exec	exec;

	if (init_structs(&exec, av) < 0)
		return (-1);
	if (creat_and_start_awindow(&exec) < 0)
		return (gc_free_all(), -1);
	exec.no = ft_texutre11(&exec, exec.text.no);
	exec.so = ft_texutre11(&exec, exec.text.so);
	exec.we = ft_texutre11(&exec, exec.text.we);
	exec.ea = ft_texutre11(&exec, exec.text.ea);
	exec.d = ft_texutre11(&exec, "./png/door.png");
	set_player_info(&exec);
	ray_casting(&exec);
	mlx_loop_hook(exec.mlx, &catch_moves, &exec);
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
	if (ac != 2)
		return (write(0, "Error\ninvalid argument\n", 23), 1);
	if (check_extention(av[1]))
		return (write(0, "Error\ninvalid extention\n", 24), 1);
	if (start_cub(av) < 0)
		return (1);
}
