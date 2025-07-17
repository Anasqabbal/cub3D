/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:48:46 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/07 09:58:09 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_all_is_full(t_texture *texture)
{
	if (texture->ea != NULL && texture->no != NULL
		&& texture->so != NULL && texture->we != NULL
		&& texture->f[0] >= 0 && texture->f[1] >= 0
		&& texture->f[2] >= 0 && texture->c[0] >= 0
		&& texture->c[1] >= 0 && texture->c[2] >= 0)
		return (1);
	return (0);
}

static void	fill_textures(char *str, t_texture *texture, int i, int j)
{
	if (str[j] == 'N' && str[j + 1] == 'O')
		texture->no = ft_strdup1(&str[i]);
	if (str[j] == 'S' && str[j + 1] == 'O')
		texture->so = ft_strdup1(&str[i]);
	if (str[j] == 'W' && str[j + 1] == 'E')
		texture->we = ft_strdup1(&str[i]);
	if (str[j] == 'E' && str[j + 1] == 'A')
		texture->ea = ft_strdup1(&str[i]);
}

int	go_to_check(char *str, t_texture *texture, int i)
{
	int	j;

	while (str[i] == ' ')
		i++;
	j = i;
	if (((str[i] == 'F') || (str[i] == 'C'))
		&& (str[i + 1] == ' '))
	{
		if (pars_color_floor_ceiling(str, texture, i))
			return (1);
	}
	else if (((str[i] == 'N' && str[i + 1] == 'O')
			|| (str[i] == 'S' && str[i + 1] == 'O')
			|| (str[i] == 'W' && str[i + 1] == 'E')
			|| (str[i] == 'E' && str[i + 1] == 'A'))
		&& (str[i + 2] == ' '))
	{
		i += 2;
		while (str[i] == ' ')
			i++;
		fill_textures(str, texture, i, j);
	}
	else
		return (write(2, "Error\nerror in direction\n", 25), 1);
	return (0);
}

int	read_textures_colors(t_cub *cub, int fd, t_texture *texture)
{
	char	*trim;
	int		i;

	while (cub->file != NULL)
	{
		i = 0;
		trim = ft_strtrim(cub->file, " ");
		while (trim[i])
			i++;
		if ((i > 0) && trim[i - 1] != '\n')
			return (close(fd), write(2, "Error\nerror new line\n", 21), 1);
		if (i == 1 && trim[i - 1] == '\n')
		{
			cub->file = get_next_line(fd);
			continue ;
		}
		if (check_all_is_full(texture))
			break ;
		if (go_to_check(cub->file, texture, 0))
			return (close(fd), 1);
		cub->file = get_next_line(fd);
	}
	return (0);
}
