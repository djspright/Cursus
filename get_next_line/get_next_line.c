/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:42:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/06/16 04:02:30 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *saved_buf)
{
	size_t	i;
	char	*next_part;
	char	*new_saved_buf;

	i = 0;
	while (saved_buf[i] && saved_buf[i] != '\n')
		i++;
	if (!saved_buf[i])
	{
		free(saved_buf);
		return (NULL);
	}
	next_part = saved_buf + i + 1;
	if (*next_part == '\0')
	{
		free(saved_buf);
		return (NULL);
	}
	new_saved_buf = ft_strdup(next_part);
	free(saved_buf);
	return (new_saved_buf);
}

char	*ft_line(char *saved_buf)
{
	char	*line;
	size_t	i;
	size_t	line_len;

	i = 0;
	if (!saved_buf || !saved_buf[0])
		return (NULL);
	while (saved_buf[i] && saved_buf[i] != '\n')
		i++;
	if (saved_buf[i] == '\n')
		line_len = i + 1;
	else
		line_len = i;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, saved_buf, line_len + 1);
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*read_buf;
	ssize_t	bytes_read;

	read_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buf);
			return (NULL);
		}
		read_buf[bytes_read] = 0;
		res = gnl_strjoin(res, read_buf);
		if (ft_strchr(read_buf, '\n'))
			break ;
	}
	free(read_buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*saved_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	saved_buf = read_file(fd, saved_buf);
	if (!saved_buf)
		return (NULL);
	line = ft_line(saved_buf);
	saved_buf = ft_next(saved_buf);
	return (line);
}
