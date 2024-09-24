/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:19:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/24 12:12:34 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../cub3d.h"

double  degree_to_rad(double deg)
{
    return (deg * (M_PI / 180));
}

double rad_to_degree(double rad)
{
    return (rad * (180.0 / M_PI));
}