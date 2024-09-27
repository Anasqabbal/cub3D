/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:07:07 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/27 16:13:10 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int file_len(t_info *info)
{
    int     i;
    int     fd;
    char    *res;

    i = 0;
    fd = open(info->path, O_RDONLY);
    if (fd < 0)
        return (1);
    res = info->path;
    while(1)
    {
        res = get_next_line(fd);
        if (!res)
           break ;
        free(res);
        i++;
    }
    close (fd);
    return (i);
}

char **cub_get_map(t_info *inf, int i)
{
    int     fd;
    char     **res;
    int     len;
    char    *res1;

    len = file_len(inf);
    if (len == 0)
        return (0);
    fd = open(inf->path, O_RDONLY);
    if (fd < 0)
        return (perror("open"), NULL);
    res = malloc(sizeof(char *) * (len + 1));
    if (!res)
        return (NULL);
    res1 = NULL;
    while(1)
    {
        res1 = get_next_line(fd);
        if (!res1)
            break ;
        res[i++] = ft_strdup(res1);
        free(res1);
    }
    res[len] = NULL;
    return (close (fd), inf->hei = len, res);
}
