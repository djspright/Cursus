/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:07:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:07:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	find_rank(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	compress_values(t_data *data)
{
	int	*sorted_array;
	int	i;
	int	original_value;

	sorted_array = malloc(sizeof(int) * data->a->size);
	if (!sorted_array)
		return ;
	i = 0;
	while (i < data->a->size)
	{
		sorted_array[i] = data->a->array[(data->a->head + i) % data->a->capacity];
		i++;
	}
	bubble_sort(sorted_array, data->a->size);
	i = 0;
	while (i < data->a->size)
	{
		original_value = data->a->array[(data->a->head + i) % data->a->capacity];
		data->a->array[(data->a->head + i) % data->a->capacity] =
			find_rank(sorted_array, data->a->size, original_value);
		i++;
	}
	free(sorted_array);
}