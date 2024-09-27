/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:19:47 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/26 17:56:11 by anqabbal         ###   ########.fr       */
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

double basic_cal(int x, int y, int t, int ind)
{
    /*      
               / \
              /   \
             /  x  \
            /       \
           /________ \
          /           \
         /  y   *   t  \
        /_______________\
    
    */
    /* we need x*/
    
    double res;

    if (ind == 1) /* find x*/
       res = y * t;
    else if (ind == 2) /*find y*/
        res = x / t;
    else
        res = x / y; /*find  t*/
    return (res);
}