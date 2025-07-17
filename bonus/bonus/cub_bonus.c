/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:17:41 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 11:31:49 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

mlx_image_t	*ft_texutre11(t_exec *exec, char *path_texture)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path_texture);
	if (!texture)
	{
		write(2, "Errorz\ninvalid path", 19);
		ft_putendl_fd(path_texture, 2);
		clean_and_exit(exec);
	}
	image = mlx_texture_to_image(exec->mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		clean_and_exit(exec);
		exit(1);
	}
	mlx_delete_texture(texture);
	ft_lstadd_back(&exec->lst, ft_lstnew(image));
	return (image);
}

static void	fill_bonus_info(t_exec *exec)
{
	int		i;

	i = 0;
	exec->lst = NULL;
	exec->ms.sensitivity = 0.1 / 30;
	exec->ms.prevx = exec->info.win_wid / 2;
	exec->ms.prevy = exec->info.win_hei / 2;
	exec->no = ft_texutre11(exec, exec->text.no);
	exec->so = ft_texutre11(exec, exec->text.so);
	exec->we = ft_texutre11(exec, exec->text.we);
	exec->ea = ft_texutre11(exec, exec->text.ea);
	exec->d = ft_texutre11(exec, "./png/door.png");
	exec->odll = ft_texutre11(exec, "./png/openll.png");
	exec->odrr = ft_texutre11(exec, "./png/openrr.png");
	exec->odlr = ft_texutre11(exec, "./png/openlr.png");
	exec->odrl = ft_texutre11(exec, "./png/openrl.png");
	exec->wp.shtnb = 30;
	exec->wp.rldnb = 5;
	exec->wp.blt = 3;
	read_images(exec, 0, "./png/gun/hld/hld_", 1);
	read_images(exec, 1, "./png/gun/sht/sht_", exec->wp.shtnb);
	read_images(exec, 2, "./png/gun/rld/rld_", exec->wp.rldnb);
	exec->frst = 1;
}

int	start_cub(char **av)
{
	t_exec	exec;

	if (init_structs(&exec, av) < 0)
		return (-1);
	if (creat_and_start_awindow(&exec) < 0)
		return (gc_free_all(), -1);
	set_player_info(&exec);
	fill_bonus_info(&exec);
	mlx_loop_hook(exec.mlx, mouse_fun, &exec);
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
