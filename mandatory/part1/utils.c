/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:20:52 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/07 09:58:17 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_color_value(t_exec *exec, float angle, int *color, t_ray *ray)
{
	if (ray->hv == 0 && ((angle >= 0 && angle < M_PI_2)
			|| (angle >= 3 * M_PI_2 && angle < 2 * M_PI)))
		*color = get_pixel(exec->we->pixels, ray->o);
	else if (ray->hv == 0 && angle >= M_PI_2 && angle < 3 * M_PI_2)
		*color = get_pixel(exec->ea->pixels, ray->o);
	else if (ray->hv == 1 && angle >= 0 && angle < M_PI)
		*color = get_pixel(exec->so->pixels, ray->o);
	else if (ray->hv == 1 && angle >= M_PI && angle < 2 * M_PI)
		*color = get_pixel(exec->no->pixels, ray->o);
}

void	draw_the_textures(t_exec *exec, float angle, int *y, t_ray *ray)
{
	int	ofsetx;
	int	ofsety;
	int	color;
	int	x;
	int	top;

	x = 0;
	if (ray->hv == 1)
		ofsetx = (int)ray->dx % PIXELS;
	else
		ofsetx = (int)ray->dy % PIXELS;
	while ((int)x++ < ray->wall_height && x <= (int)exec->info.win_hei)
	{
		top = *y + (ray->wall_height / 2) - (exec->info.win_hei / 2);
		ofsety = top * ((float)PIXELS / ray->wall_height);
		ray->o = ((PIXELS * ofsety) + ofsetx) * 4;
		if (ray->o >= 0 && ray->o + 3 < (PIXELS * PIXELS * 4))
			set_color_value(exec, angle, &color, ray);
		mlx_put_pixel(exec->wind_image, ray->x, (*y)++, color);
	}
}

int	switch_rgb_hex(int color[3], int a)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | a);
}

int	is_invalid(char **map, int i, size_t j)
{
	return (
		((i == 0 || j == 0) && (map[i][j] != '1')) ||
		(map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == '\0')
		|| ((map[i - 1][j] == ' ' || map[i - 1][j] == '\0')) ||
		(map[i + 1] == NULL
		|| (map[i + 1][j] == ' ' || map[i + 1][j] == '\0')));
}
