/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:19:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/22 09:29:31 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../cub3d.h"

double  degree_to_rad(double deg)
{
    return (deg * (PI / 180.0));
}

double rad_to_degree(double rad)
{
    return (rad * (180.0 / PI));
}