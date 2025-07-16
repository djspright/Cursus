/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:42:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/07/10 18:29:42 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *saved_buf)
{
	char	*next_part;
	char	*new_saved_buf;

	if (!saved_buf)
		return (NULL);
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

int	read_and_join(int fd, char **saved_buf, char *read_buf)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		if (*saved_buf)
			free(*saved_buf);
		*saved_buf = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	read_buf[bytes_read] = '\0';
	*saved_buf = gnl_strjoin(*saved_buf, read_buf);
	if (!*saved_buf)
		return (-1);
	return (1);
}

char	*read_file(int fd, char *saved_buf)
{
	char	*read_buf;
	int		result;

	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
	{
		if (saved_buf)
			free(saved_buf);
		return (NULL);
	}
	while (!saved_buf || !ft_strchr(saved_buf, '\n'))
	{
		result = read_and_join(fd, &saved_buf, read_buf);
		if (result <= 0)
			break ;
		if (saved_buf && ft_strchr(saved_buf, '\n'))
			break ;
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
	{
		saved_buf = NULL;
		return (NULL);
	}
	line = ft_line(saved_buf);
	saved_buf = ft_next(saved_buf);
	if (!line)
	{
		if (saved_buf)
		{
			free(saved_buf);
			saved_buf = NULL;
		}
		return (NULL);
	}
	return (line);
}
