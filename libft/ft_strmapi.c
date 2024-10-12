/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:16:29 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/27 15:08:44 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		len;
	int		i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	arr = (char *)gc_malloc(sizeof(char) * len + 1);
	i = 0;
	if (!arr)
		return (0);
	while (i < len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	*(arr + i) = '\0';
	return (arr);
}
