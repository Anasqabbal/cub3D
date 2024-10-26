/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:17:41 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/26 17:49:20 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void  read_images(t_exec *exec, int frmnb, char *name)
{
	char *src;
	char *tmp;
	int	i;

	i = -1;
	(void) exec;
	exec->sh = malloc(sizeof(mlx_image_t) * frmnb);
	while (++i < frmnb)
	{
		tmp = ft_itoa(i);
		src = ft_strjoin(name, tmp);
		src = ft_strjoin(src, ".png");
		// free(tmp);
		printf("i == %d\n", i);
		exec->sh[i] = ft_texture(exec, src);
	}
}

void initialize_buttons(t_exec *exec)
{
	exec->stl.d = 0;
	exec->stl.l = 0;
	exec->stl.r = 0;
	exec->stl.u = 0;
}

int	start_cub(char **av)
{
	t_exec	exec;

	if (init_structs(&exec, av) < 0)
		return (-1);
	if (creat_and_start_awindow(&exec) < 0)
		return (gc_free_all(), -1);
	set_player_info(&exec);
	exec.ms.sensitivity = 0.1 / 30;
	exec.ms.prevx = exec.info.win_wid / 2;
    exec.ms.prevy = exec.info.win_hei / 2;
	exec.no = ft_texture(&exec, exec.text.NO);
    exec.so = ft_texture(&exec, exec.text.SO);
    exec.we = ft_texture(&exec, exec.text.WE);
    exec.ea = ft_texture(&exec, exec.text.EA);
    exec.d = ft_texture(&exec, "./png/door.png");
	exec.wp = ft_texture(&exec, "./png/wp.png");
	exec.wpshtt = ft_texture(&exec, "./png/wpsht.png");
	read_images(&exec, 5, "./png/mv/gun_mv_");
	initialize_buttons(&exec);
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

void f(void){system("leaks cub3D_bonus");}

int	main(int ac, char **av)
{
	// atexit(f);
	if (ac != 2 || ac > 3)
		return (write(0, "error\ninvalid argument\n", 23), 1);
	if (check_extention(av[1]))
		return (write(0, "error\ninvalid extention\n", 24), 1);
    if (start_cub(av) < 0)
        return (1);
}