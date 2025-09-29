/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:09:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:46:53 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_and_parse(int argc, char **argv, t_data **data)
{
	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	*data = parse_args(argc, argv);
	if (!*data)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (2);
}

static int	process_operations(t_data *data)
{
	char	*line;

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
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		result;

	result = validate_and_parse(argc, argv, &data);
	if (result != 2)
		return (result);
	if (process_operations(data))
		return (1);
	if (is_sorted(data->a) && data->b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_data(data);
	return (0);
}
