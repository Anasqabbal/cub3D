/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:19:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/18 17:19:54 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	degree_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

float	rad_to_degree(float rad)
{
	return (rad * (180.0 / M_PI));
}
