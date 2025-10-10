/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/10 21:31:27 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*allocate_and_copy(char *buffer, int len)
{
	char	*line;
	int		i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	read_input_to_buffer(char *buffer)
{
	int		i;
	int		ret;

	i = 0;
	while (i < 999)
	{
		ret = read(0, &buffer[i], 1);
		if (ret <= 0)
			break ;
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*get_next_line(void)
{
	char	buffer[1000];
	int		len;

	len = read_input_to_buffer(buffer);
	if (len == 0)
		return (NULL);
	buffer[len] = '\0';
	return (allocate_and_copy(buffer, len));
}
