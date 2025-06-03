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
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	t_uint8_t	uc;

	uc = (t_uint8_t)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*extract_line_and_update_saved(char **saved_ptr)
{
	char	*line;
	char	*newline_ptr;
	char	*next_saved;
	size_t	line_len;

	if (!saved_ptr || !*saved_ptr || !**saved_ptr)
		return (NULL);
	newline_ptr = ft_strchr(*saved_ptr, '\n');
	if (newline_ptr)
	{
		line_len = newline_ptr - *saved_ptr + 1;
		line = ft_substr(*saved_ptr, 0, line_len);
		if (!line)
			return (NULL);
		next_saved = ft_strdup(newline_ptr + 1);
		if (!next_saved && *(newline_ptr + 1) != '\0')
		{
			free(line);
			return (NULL);
		}
		free(*saved_ptr);
		*saved_ptr = next_saved;
		return (line);
	}
	return (NULL);
}

static char	*join_and_extract(char **saved_ptr, const char *buf)
{
	char	*tmp_saved;
	char	*line;

	tmp_saved = gnl_strjoin(*saved_ptr, buf);
	if (!tmp_saved)
	{
		*saved_ptr = NULL;
		return ((char *)-1);
	}
	*saved_ptr = tmp_saved;
	line = extract_line_and_update_saved(saved_ptr);
	return (line);
}

static char	*extract_remaining(char **saved_ptr, ssize_t bytes_read)
{
	char	*line;

	if (bytes_read < 0)
	{
		free(*saved_ptr);
		*saved_ptr = NULL;
		return (NULL);
	}
	if (*saved_ptr && **saved_ptr)
	{
		line = ft_strdup(*saved_ptr);
		free(*saved_ptr);
		*saved_ptr = NULL;
		return (line);
	}
	free(*saved_ptr);
	*saved_ptr = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		read_buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = extract_line_and_update_saved(&s_buf);
	if (line)
		return (line);
	while (1)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		read_buf[bytes_read] = '\0';
		line = join_and_extract(&s_buf, read_buf);
		if (line == (char *)-1)
			return (NULL);
		if (line)
			return (line);
	}
	return (extract_remaining(&s_buf, bytes_read));
}
