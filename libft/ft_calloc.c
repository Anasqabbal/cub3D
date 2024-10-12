/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:04 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/27 15:00:53 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (((int)count < 0 && (int)size < 0))
		return (0);
	arr = gc_malloc(size * count);
	if (!arr)
		return (0);
	ft_bzero(arr, count * size);
	return (arr);
}
