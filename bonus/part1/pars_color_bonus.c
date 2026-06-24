/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:55:32 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/07 10:00:36 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	fill_color_texture1(char *str, t_texture *tex, char **new, int j)
{
	int	i;

	if (str[j] == 'C')
	{
		i = 0;
		while (new[i])
		{
			tex->c[i] = ft_atoi(new[i]);
			if (tex->c[i] > 255)
				return (write(2, "error\nthis number is > 255\n", 27), 1);
			i++;
		}
		tex->c_color = switch_rgb_hex(tex->c, 255);
	}
	return (0);
}

static int	fill_color_texture(char *str, t_texture *texture, char **new, int j)
{
	int	i;

	if (str[j] == 'F')
	{
		i = 0;
		while (new[i])
		{
			texture->f[i] = ft_atoi(new[i]);
			if (texture->f[i] > 255)
				return (write(2, "error\nthis number is > 255\n", 27), 1);
			i++;
		}
		texture->f_color = switch_rgb_hex(texture->f, 255);
	}
	if (fill_color_texture1(str, texture, new, j))
		return (1);
	return (0);
}

static int	check_color2(char **new, int j, char *str, t_texture *texture)
{
	char	*trim;
	int		o;
	int		count;
	int		k;

	k = -1;
	while (new[++k])
	{
		o = 0;
		count = 0;
		trim = ft_strtrim(new[k], " ");
		while (trim[o])
		{
			if (trim[o] == ' ')
				return (write(2, "error\ncolor is not correct\n", 27), 1);
			if (ft_isdigit(trim[o]))
				count ++;
			o++;
		}
		if (count > 3)
			return (write(2, "error\ncolor is not correct\n", 27), 1);
	}
	if (fill_color_texture(str, texture, new, j))
		return (1);
	return (0);
}

static int	check_color(char *str1, char *str, t_texture *texture, int j)
{
	int	sq;
	int	i;

	i = 0;
	sq = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == ',')
			sq++;
		if (str1[i] == ' ')
		{
			i++;
			continue ;
		}
		if ((str1[i] == ',' && str1[i + 1] == ','))
			return (write(2, "Error\nInvalid character in color\n", 33), 1);
		if (str1[i] == ',' && (str1[i + 1] == '\n' || str1[i + 1] == '\0'))
			return (write(2, "Errror\ninvalid caracter in F or C\n", 34), 1);
		i++;
	}
	if (sq > 2)
		return (write(2, "Error\ninvalid color F or C\n", 27), 1);
	if (check_color2(ft_split(str1, ','), j, str, texture))
		return (1);
	return (0);
}

int	pars_color_floor_ceiling(char *str, t_texture *texture, int j)
{
	char	*trim;
	int		i;

	i = j + 1;
	trim = ft_strtrim(&str[i], "\n");
	trim = ft_strtrim(trim, " ");
	i = 0;
	while (trim[i] != '\0')
	{
		if (!ft_isdigit(trim[i]) && trim[i] != ',' && trim[i] != ' ')
		{
			write(2, "Error\nadd just numbers in F and C\n", 34);
			return (1);
		}
		i++;
	}
	if (trim[i] == ',')
		return (write(2, "Error\nError:`,` in the first \n", 30), 1);
	if (check_color(trim, str, texture, j))
		return (1);
	return (0);
}
