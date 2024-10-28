/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:08:26 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/28 08:58:13 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d_bonus.h"

int get_element_from_map(t_exec *exec, char c, int ind)
{
    int x;
    int y;
    int fl;

    y = -1;
    fl = 0;
    while (exec->info.map[++y])
    {
        x = -1;
        while (exec->info.map[y][++x])
        {
            if (exec->info.map[y][x] == c && ++fl)
                break ;
        }
        if (fl)
            break ;
    }
    if (ind)
        return (y);
    printf("x == %d and y == %d", x, y);
    return (x);
}

void	fill_xstart_end(t_exec *exec, int *start, int *end, float diff)
{
	int	org_len;
	int	org_pos;

	org_len = exec->info.map_wid / PIXELS;
	org_pos = exec->ply.px / PIXELS;
	*start = org_pos - diff;
	*end = org_pos + (diff);
	if (*start < 0)
	{
		*end += *start * (-1);
		*start = 0;
	}
	else if (*end >= org_len)
	{
		*start -= (*end - org_len);
		*end = org_len;
	}
}

void	fill_ystart_end(t_exec *exec, int *start, int *end, float diff)
{
	int	org_len;
	int	org_pos;

	org_len = exec->info.map_hei / PIXELS;
	org_pos = exec->ply.py / PIXELS;
	*start = org_pos - diff;
	*end = org_pos + diff;
	if (*start < 0)
	{
		*end += *start * (-1);
		*start = 0;
	}
	else if (*end >= org_len)
	{
		*start -= (*end - org_len);
		*end = org_len;
	}
}