/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:09:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:09:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	execute_operation(t_data *data, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(data, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(data, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(data, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(data, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(data, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(data, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(data, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(data, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(data, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(data, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(data, 0);
	else
		return (0);
	return (1);
}

static char	*get_next_line(void)
{
	char	*line;
	char	buffer[1000];
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
	if (i == 0)
		return (NULL);
	buffer[i] = '\0';
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*line;

	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	data = parse_args(argc, argv);
	if (!data)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (1)
	{
		line = get_next_line();
		if (!line)
			break ;
		if (!execute_operation(data, line))
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			free_data(data);
			return (1);
		}
		free(line);
	}
	if (is_sorted(data->a) && data->b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_data(data);
	return (0);
}