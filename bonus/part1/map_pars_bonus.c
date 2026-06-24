/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:29:11 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/07 10:00:31 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	check_valid_map(char **map, int i, int count)
{
	int	j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != ' ' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != 'D')
				return (write(2, "Error\ninvalid caracter in map\n", 30), 1);
			if (map[i][j] == 'S'
				|| map[i][j] == 'N'
				|| map[i][j] == 'W'
				|| map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (write(2, "Error\ncheck palyer in map\n", 26), 1);
	return (0);
}

static int	check_map(char **map, int *i, size_t *j)
{
	int	k;

	while (map[*i][*j] == ' ')
		(*j)++;
	if (map[*i][*j] == '\0')
	{
		k = *i - 1;
		while (map[k][*j] == ' ')
			(*j)++;
		while (map[k][*j])
		{
			if (map[k][*j] != '1')
				return (write(2, "Error\nInvalid map\n", 19), 1);
			(*j)++;
		}
		(*i)++;
		return (2);
	}
	return (0);
}

int	check_door(char **map, int i, int j)
{
	if ((map[i][j + 1] == '1' && map[i][j - 1] == '1'))
	{
		if (map[i + 1][j] == '1' || map[i - 1][j] == '1')
			return (write(2, "Error\nInvalid map\n", 19), 1);
	}
	else if (map[i + 1][j] == '1' && map[i - 1][j] == '1')
	{
		if (map[i][j + 1] == '1' || map[i][j - 1] == '1')
			return (write(2, "Error\nInvalid map\n", 19), 1);
	}
	else if (map[i + 1][j] == 'D' || map[i][j + 1] == 'D')
		return (write(2, "Error\nInvalid map\n", 19), 1);
	return (0);
}

static int	check_map1(char **map, int i, int j)
{
	while (map[i][j])
	{
		if ((map[i][j] == '0'
			|| map[i][j] == 'N'
			|| map[i][j] == 'W'
			|| map[i][j] == 'E'
			|| map[i][j] == 'S'
			|| map[i][j] == 'D')
			&& is_invalid(map, i, j))
			return (write(2, "Error\nInvalid map\n", 18), 1);
		if (map[i][j] == 'D')
		{
			if (check_door(map, i, j))
				return (1);
			j++;
			continue ;
		}
		else if (map[i][j] == 'D' && ((map[i][j + 1] != '1'
			&& map[i][j - 1] != '1') || (map[i + 1][j] != '1'
			&& map[i - 1][j] != '1')))
			return (write(2, "Error\nInvalid mapu\n", 19), 1);
		j++;
	}
	return (0);
}

int	parsing_map(t_cub *cub, int len)
{
	size_t	j;
	int		i;
	int		res;

	i = 0;
	cub->map1 = ft_split1(cub->map, '\n', len);
	if (check_valid_map(cub->map1, 0, 0))
		return (1);
	while (cub->map1[i])
	{
		j = 0;
		res = check_map(cub->map1, &i, &j);
		if (res == 2)
			continue ;
		else if (res == 1)
			return (1);
		if (check_map1(cub->map1, i, j))
			return (1);
		i++;
	}
	cub->len_h = i;
	return (0);
}
