/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_data *data, int min_idx)
{
	if (min_idx <= data->a->size / 2)
	{
		while (min_idx > 0)
		{
			ra(data, 1);
			min_idx--;
		}
	}
	else
	{
		min_idx = data->a->size - min_idx;
		while (min_idx > 0)
		{
			rra(data, 1);
			min_idx--;
		}
	}
}

void	sort_four(t_data *data)
{
	int	min_idx;

	min_idx = find_min_index(data->a);
	rotate_to_top(data, min_idx);
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
}

void	sort_five_optimized(t_data *data)
{
	int	min_idx;

	min_idx = find_min_index(data->a);
	rotate_to_top(data, min_idx);
	pb(data, 1);
	min_idx = find_min_index(data->a);
	rotate_to_top(data, min_idx);
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
	pa(data, 1);
}

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

void	compress_values(t_data *data)
{
	int		*sorted_arr;
	int		*original_arr;
	t_node	*current;
	int		i;

	sorted_arr = malloc(sizeof(int) * data->total_size);
	if (!sorted_arr)
		return ;
	original_arr = malloc(sizeof(int) * data->total_size);
	if (!original_arr)
	{
		free(sorted_arr);
		return ;
	}
	current = data->a->head->next;
	i = 0;
	while (current != data->a->head)
	{
		sorted_arr[i] = current->value;
		original_arr[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(sorted_arr, data->total_size);
	apply_compression(data, sorted_arr, original_arr);
	free(sorted_arr);
	free(original_arr);
}