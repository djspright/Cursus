/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_recursive_quick.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_median(t_stack *stack, int size)
{
	int	*arr;
	int	i;
	int	j;
	int	temp;
	int	median;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = get_at_index(stack, i);
		i++;
	}
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
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	quick_sort_a(t_data *data, int size)
{
	int	pivot;
	int	pushed;
	int	i;
	int	rotated;

	if (size <= 3)
	{
		handle_small_a(data, size);
		return ;
	}
	pivot = get_median(data->a, size);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		if (get_at_index(data->a, 0) < pivot)
		{
			pb(data, 1);
			pushed++;
		}
		else
		{
			ra(data, 1);
			rotated++;
		}
		i++;
	}
	if (data->a->size > size - pushed)
		while (rotated-- > 0)
			rra(data, 1);
	quick_sort_a(data, size - pushed);
	quick_sort_b(data, pushed);
}

void	quick_sort_b(t_data *data, int size)
{
	int	pivot;
	int	pushed;
	int	i;
	int	rotated;

	if (size <= 2)
	{
		handle_small_b(data, size);
		return ;
	}
	pivot = get_median(data->b, size);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		if (get_at_index(data->b, 0) >= pivot)
		{
			pa(data, 1);
			pushed++;
		}
		else
		{
			rb(data, 1);
			rotated++;
		}
		i++;
	}
	if (data->b->size > size - pushed)
		while (rotated-- > 0)
			rrb(data, 1);
	quick_sort_a(data, pushed);
	quick_sort_b(data, size - pushed);
}

void	recursive_quick_sort(t_data *data)
{
	compress_values(data);
	quick_sort_a(data, data->a->size);
}