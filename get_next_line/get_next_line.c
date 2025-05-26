/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:42:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/26 16:31:37 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	char		*line;
	static char	*saved_buffer;
	ssize_t		bytes_read;
	size_t		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	line = NULL;
	if (!saved_buffer)
	{
		while (i < BUFFER_SIZE)
		{
			bytes_read = read(fd, buf, sizeof(buf) - 1);
			if (bytes_read > 0)
				buf[bytes_read] = '\0';
			if (buf[i] == '\n')
			{
				line = ft_substr(buf, 0, i);
				if (!line)
					return (NULL);
				saved_buffer = ft_substr(buf, i + 2, bytes_read);
				return (line);
			}
			i++;
		}
	}
	while (i < BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, sizeof(buf) - 1);
		if (bytes_read > 0)
			buf[bytes_read] = '\0';
		if (buf[i] == '\n')
		{
			line = ft_substr(buf, 0, i);
			if (!line)
				return (NULL);
			saved_buffer = ft_substr(buf, i + 2, bytes_read);
			return (line);
		}
		i++;
	}
	if (EOF)
		return (line);
	return (NULL);
}
