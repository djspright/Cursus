/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 21:58:53 by shkondo          ###   ########.fr       */
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
		while (j < size - i - 1)
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

static void	apply_compression(t_data *data, int *sorted, int *original)
{
	t_node	*current;
	int		i;
	int		j;

	current = data->a->head->next;
	i = 0;
	while (current != data->a->head)
	{
		j = 0;
		while (j < data->total_size)
		{
			if (original[i] == sorted[j])
			{
				current->value = j;
				sorted[j] = -2147483648;
				break ;
			}
			j++;
		}
		current = current->next;
		i++;
	}
}

static void	copy_values(t_data *data, int *sorted, int *original)
{
	t_node	*current;
	int		i;

	current = data->a->head->next;
	i = 0;
	while (current != data->a->head)
	{
		sorted[i] = current->value;
		original[i] = current->value;
		current = current->next;
		i++;
	}
}

void	compress_values(t_data *data)
{
	int	*sorted_arr;
	int	*original_arr;

	sorted_arr = malloc(sizeof(int) * data->total_size);
	if (!sorted_arr)
		return ;
	original_arr = malloc(sizeof(int) * data->total_size);
	if (!original_arr)
	{
		free(sorted_arr);
		return ;
	}
	copy_values(data, sorted_arr, original_arr);
	bubble_sort(sorted_arr, data->total_size);
	apply_compression(data, sorted_arr, original_arr);
	free(sorted_arr);
	free(original_arr);
}
