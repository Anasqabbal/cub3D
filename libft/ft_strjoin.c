/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:55:31 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/01 11:13:22 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		len2;
	char	*arr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strjoin("", s2));
	if (!s2)
		return (ft_strjoin(s1, ""));
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	arr = (char *)gc_malloc(sizeof(char) * len + len2 + 1);
	if (!arr)
		return (0);
	ft_memmove(arr, s1, len);
	ft_memmove(arr + len, s2, len2);
	*(arr + len + len2) = '\0';
	return (arr);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char		*ml;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strjoin("", s2));
	if (!s2)
		return (ft_strjoin(s1, ""));
	ml = (char *)gc_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ml)
		return (NULL);
	ft_memcpy(ml, s1, ft_strlen(s1));
	ft_memcpy(ml + ft_strlen(s1), s2, ft_strlen(s2));
	ml[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ml);
}
