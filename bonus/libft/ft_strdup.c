/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:17:14 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/01 11:13:16 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*arr;

	len = ft_strlen(s1);
	arr = (char *)gc_malloc((len + 1) * (sizeof (char)));
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, len);
	arr[len] = '\0';
	return (arr);
}

char	*ft_strdup1(const char *s1)
{
	int		len;
	int		i;
	char	*arr;

	len = 0;
	i = 0;
	while (s1[len] && s1[len] != '\n')
		len ++;
	arr = (char *)gc_malloc((len + 1) * (sizeof (char)));
	if (!arr)
		return (0);
	while (s1[i] && s1[i] != '\n')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
