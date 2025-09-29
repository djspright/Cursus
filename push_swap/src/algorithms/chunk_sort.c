/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 01:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 07:46:45 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_count(int size)
{
	if (size <= 10)
		return (1);
	if (size <= 100)
		return (5);
	if (size <= 500)
		return (11);
	return (15);
}

static void	push_chunk_to_b(t_data *data, int min_rank, int max_rank)
{
	int	rotations;
	int	initial_size;
	int	mid_rank;

	initial_size = data->a->top + 1;
	rotations = 0;
	mid_rank = (min_rank + max_rank) / 2;
	while (rotations < initial_size && data->a->top >= 0)
	{
		if (data->a->array[data->a->top] >= min_rank
			&& data->a->array[data->a->top] <= max_rank)
		{
			handle_push_to_b(data, mid_rank);
			rotations = 0;
			initial_size = data->a->top + 1;
		}
		else
		{
			ra(data, 1);
			rotations++;
		}
	}
}

static int	calculate_max_rank(int i, int chunk_count, int chunk_size,
	int total_size)
{
	int	adaptive_size;

	if (i == chunk_count - 1)
		return (total_size - 1);
	adaptive_size = calculate_adaptive_size(chunk_size, i, chunk_count);
	return (i * chunk_size + adaptive_size - 1);
}

static void	sort_chunks_to_b(t_data *data)
{
	int	chunk_count;
	int	chunk_size;
	int	i;
	int	max_rank;

	chunk_count = get_chunk_count(data->total_size);
	chunk_size = data->total_size / chunk_count;
	i = 0;
	while (i < chunk_count && data->a->top >= 2)
	{
		max_rank = calculate_max_rank(i, chunk_count, chunk_size,
				data->total_size);
		push_chunk_to_b(data, i * chunk_size, max_rank);
		i++;
	}
}

void	sort_large(t_data *data)
{
	sort_chunks_to_b(data);
	if (data->a->top >= 0)
	{
		if (data->a->top == 2)
			sort_three(data);
		else
			sort_small(data);
	}
	push_back_sorted_from_b(data);
	final_rotation(data);
}

int	calculate_adaptive_size(int chunk_size, int i, int chunk_count)
{
	int adaptive_size;

	adaptive_size = chunk_size;
	if (i >= chunk_count / 2)
		adaptive_size = chunk_size + chunk_size / 4;
	return (adaptive_size);
}

void	handle_push_to_b(t_data *data, int mid_rank)
{
	pb(data, 1);
	if (data->b->top > 0 && data->b->array[data->b->top] < mid_rank)
		rb(data, 1);
}
