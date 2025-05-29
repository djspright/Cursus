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

static char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*extract_line_and_update_saved(char **saved_buffer_ptr)
{
	char	*line;
	char	*newline_char_ptr;
	char	*tmp_next_saved;
	size_t	line_len;

	if (!saved_buffer_ptr || !*saved_buffer_ptr
		|| (*saved_buffer_ptr)[0] == '\0')
		return (NULL);
	newline_char_ptr = ft_strchr(*saved_buffer_ptr, '\n');
	if (newline_char_ptr != NULL)
	{
		line_len = newline_char_ptr - *saved_buffer_ptr;
		line = ft_substr(*saved_buffer_ptr, 0, line_len + 1);
		if (!line)
			return (NULL);
		tmp_next_saved = ft_strdup(newline_char_ptr + 1);
		if (!tmp_next_saved && (newline_char_ptr + 1)[0] != '\0')
		{
			free(line);
			return (NULL);
		}
		free(*saved_buffer_ptr);
		*saved_buffer_ptr = tmp_next_saved;
		return (line);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*saved_buffer;
	ssize_t		bytes_read;
	char		*tmp_saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = extract_line_and_update_saved(&saved_buffer);
	if (line)
		return (line);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		tmp_saved = gnl_strjoin(saved_buffer, buf);
		if (!tmp_saved)
		{
			free(saved_buffer);
			saved_buffer = NULL;
			return (NULL);
		}
		saved_buffer = tmp_saved;
		line = extract_line_and_update_saved(&saved_buffer);
		if (line)
			return (line);
	}
	if (bytes_read < 0)
	{
		free(saved_buffer);
		saved_buffer = NULL;
		return (NULL);
	}
	if (saved_buffer != NULL && saved_buffer[0] != '\0')
	{
		line = ft_strdup(saved_buffer);
		free(saved_buffer);
		saved_buffer = NULL;
		if (!line)
			return (NULL);
		return (line);
	}
	return (line);
	free(saved_buffer);
	saved_buffer = NULL;
	return (NULL);
}
