/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:05:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:05:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

t_data	*parse_args(int argc, char **argv)
{
	t_data	*data;
	int		*numbers;
	int		i;

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
	data = data_init(argc - 1);
	if (!data)
	{
		free(numbers);
		return (NULL);
	}
	i = 0;
	while (i < argc - 1)
	{
		data->a->array[i] = numbers[i];
		i++;
	}
	data->a->size = argc - 1;
	free(numbers);
	return (data);
}