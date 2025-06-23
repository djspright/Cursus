/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:42:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/06/23 13:54:54 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *saved_buf)
{
	char	*next_part;
	char	*new_saved_buf;

	next_part = ft_strchr(saved_buf, '\n');
	if (!next_part)
	{
		free(saved_buf);
		return (NULL);
	}
	new_saved_buf = ft_strdup(next_part + 1);
	free(saved_buf);
	if (new_saved_buf && *new_saved_buf == '\0')
	{
		free(new_saved_buf);
		return (NULL);
	}
	return (new_saved_buf);
}

char	*ft_line(char *saved_buf)
{
	char	*line;
	size_t	i;

	if (!saved_buf || !saved_buf[0])
		return (NULL);
	i = 0;
	while (saved_buf[i] && saved_buf[i] != '\n')
		i++;
	if (saved_buf[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, saved_buf, i + 1);
	return (line);
}

char	*read_file(int fd, char *saved_buf)
{
	char	*read_buf;
	ssize_t	bytes_read;

	read_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(saved_buf, '\n'))
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(read_buf);
			free(saved_buf);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		read_buf[bytes_read] = '\0';
		saved_buf = gnl_strjoin(saved_buf, read_buf);
	}
	free(read_buf);
	return (saved_buf);
}

char	*get_next_line(int fd)
{
	static char	*saved_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_buf = read_file(fd, saved_buf);
	if (!saved_buf)
		return (NULL);
	line = ft_line(saved_buf);
	saved_buf = ft_next(saved_buf);
	return (line);
}
