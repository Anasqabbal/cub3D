/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:18:54 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/27 15:13:27 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_line(char *buffer, int indice)
{
	int		len;
	char	*str;
	int		str_len;

	len = 0;
	str_len = 0;
	if (!buffer)
		return (0);
	len = 0;
	while (buffer[len])
		len++;
	str = my_strchr(buffer, '\n');
	if (!str)
		return (len);
	while (str[str_len])
		str_len++;
	if (indice == 0)
		return ((len - str_len) + 1);
	else if (indice == 1)
		return (len - (len - str_len));
	else
		return (count_line(str + 1, 0));
}

static char	*cut_(char *buffer, int indice)
{
	char	*s;
	int		len;

	len = count_line(buffer, indice);
	s = my_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	else if (indice == 0)
		my_memcpy(s, buffer, len);
	else if (indice == 1)
	{
		if (*buffer && my_strchr(buffer, '\n'))
			my_memcpy(s, (buffer + count_line(buffer, 0)), len);
	}
	return (s);
}

static char	*read_until_n_line(int fd, char *t_r)
{
	char	*buffer;
	ssize_t	n;
	char	*line;

	buffer = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (to_join(t_r, NULL, 0));
	n = 1;
	line = t_r;
	while (n)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (to_join(buffer, NULL, 0), to_join(line, NULL, 0));
		buffer[n] = '\0';
		line = to_join(line, buffer, 3);
		if (!line)
			return ( NULL);
		if (buffer && my_strchr(buffer, '\n'))
			break ;
	}
	if (line && *line == '\0')
		return (to_join(buffer, NULL, 0), line = to_join(line, NULL, 0), NULL);
	return ( line);
}

static char	*cut_the_rest(char **t_r, char **tmp, char **line)
{
	*tmp = cut_(*t_r, 1);
	if (!(*tmp))
		return (*t_r = NULL, NULL);
	if (*tmp && **tmp == '\0')
		*tmp = to_join(*tmp, NULL, 0);
	*line = cut_(*t_r, 0);
	if (!(*line))
		return ( *t_r = NULL, NULL);
	*t_r = *tmp;
	return (*line);
}

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

char	*get_next_line(int fd)
{
	static char	*t_r[OPEN_MAX];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (t_r[fd] && my_strchr(t_r[fd], '\n'))
		return (cut_the_rest(&t_r[fd], &tmp, &line));
	line = read_until_n_line(fd, t_r[fd]);
	if (!line)
	{
		t_r[fd] = NULL;
		return (NULL);
	}
	else if (line && *line == '\0')
		return (line = to_join(line, NULL, 0), to_join(t_r[fd], NULL, 0));
	t_r[fd] = cut_(line, 1);
	if (!t_r[fd])
	{
		line = NULL;
		return (NULL);
	}
	tmp = line;
	(void)tmp;
	line = cut_(line, 0);
	if (!line)
	{
		t_r[fd] = NULL;
		return (NULL);
	}
	return (line);
}
