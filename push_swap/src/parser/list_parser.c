/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*convert_to_numbers(int argc, char **argv)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (has_duplicates(numbers, argc - 1))
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}

static void	fill_stack_a(t_data *data, int *numbers, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		push_front(data->a, numbers[i]);
		i--;
	}
	data->total_size = size;
}

t_data	*parse_args(int argc, char **argv)
{
	t_data	*data;
	int		*numbers;

	numbers = convert_to_numbers(argc, argv);
	if (!numbers)
		return (NULL);
	data = data_init(argc - 1);
	if (!data)
	{
		free(numbers);
		return (NULL);
	}
	fill_stack_a(data, numbers, argc - 1);
	free(numbers);
	return (data);
}