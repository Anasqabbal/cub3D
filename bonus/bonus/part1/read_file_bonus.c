/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:35:55 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/07 10:00:42 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	init_variables_direction(t_texture *texture)
{
	texture->ea = NULL;
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->map = NULL;
	texture->f[0] = -1;
	texture->f[1] = -1;
	texture->f[2] = -1;
	texture->c[0] = -1;
	texture->c[1] = -1;
	texture->c[2] = -1;
}

int	open_file(t_cub *cub, char **av, int *fd, t_texture *texture)
{
	init_variables_direction(texture);
	*fd = open(av[1], O_RDWR);
	if (*fd < 0)
		return (1);
	cub->file = get_next_line(*fd);
	if (!(cub->file))
		return (close(*fd), write(2, "Error\nempty file\n", 17), 1);
	if (read_textures_colors(cub, *fd, texture))
		return (1);
	return (0);
}

int	read_map(t_cub *cub, t_texture *texture, int fd, size_t	j)
{
	int		i;

	cub->len = 0;
	cub->map = NULL;
	if (cub->file)
	{
		while (cub->file != NULL)
		{
			j = ft_strlen(cub->file);
			i = 0;
			while (cub->file[i])
				i++;
			if (i == 1 && cub->file[i - 1] == '\n')
				return (close(fd), write(2, "Error\nerror in map", 18), 1);
			cub->len = (j > cub->len) * j + !(j > cub->len) * cub->len;
			cub->map = ft_strjoin1(cub->map, cub->file);
			cub->file = get_next_line(fd);
		}
	}
	else
		return (close(fd), write(2, "Error\nput your map\n", 19), 1);
	if (parsing_map(cub, cub->len))
		return (close(fd), 1);
	texture->map = cub->map1;
	return (close(fd), 0);
}

int	read_file(char **av, t_cub *cub, t_texture *texture)
{
	int		fd;
	size_t	j;

	j = 0;
	if (open_file(cub, av, &fd, texture))
		return (1);
	if (read_map(cub, texture, fd, j))
		return (1);
	return (0);
}
