/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:27:17 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/01 11:05:14 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_w(const char *str, char ca)
{
	int	pos;
	int	count;

	pos = 1;
	count = 0;
	while (*str)
	{
		if (*str != ca && pos == 1)
		{
			count++;
			pos = 0;
		}
		else if (*str == ca)
			pos = 1;
		str++;
	}
	return (count);
}

static	char	**printword(char const *str, char ce, char **mall, int len)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ce && str[i])
			i++;
		if (str[i])
		{
			j = i;
			while (str[j] && str[j] != ce)
				j++;
			mall[k] = ft_calloc(sizeof(char ), (len) + 1);
			if (mall[k] == NULL)
				return (NULL);
			ft_memcpy (mall[k], &str[i], j - i);
			mall[k++][len] = '\0';
			i = j;
		}
	}
	mall[k] = NULL;
	return (mall);
}

char	**ft_split1(char const *s, char c, int len)
{
	int		cw;
	char	**ml;
	char	**ll;

	if (!s)
		return (0);
	cw = count_w(s, c);
	ml = (char **)gc_malloc(sizeof(char *) * (cw + 1));
	if (!ml)
		return (NULL);
	if (cw == 0)
	{
		ml[0] = NULL;
		return (ml);
	}
	ll = printword(s, c, ml, len);
	return (ll);
}
