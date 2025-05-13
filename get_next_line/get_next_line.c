/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:42:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/12 22:08:39 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

char	*get_next_line(int fd)
{
	char		*line;
	char		*ptr;
	char		*dst;
	static char	*saved_buffer;
	size_t		i;

	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		read(fd, &dst, i);
		if (dst[i] == '\n')
		{
			ptr = ft_strchr(line, '\n');
			dst = ft_substr(line, ptr, &ptr - &line);
			if (!dst)
				return (NULL);
			return (dst);
		}
		ptr++;
	}
	if (EOF)
		return (dst);
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	free(line);
	line = NULL;
	if (close(fd) == -1)
		perror("Error closing file");
	return (0);
}
