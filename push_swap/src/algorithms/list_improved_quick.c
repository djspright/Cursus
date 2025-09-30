/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_improved_quick.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_hold_values(t_data *data, int *hold, int min, int max)
{
	int	i;
	int	value;

	hold[0] = -1;
	hold[1] = -1;
	i = 0;
	while (i < data->a->size)
	{
		value = get_at_index(data->a, i);
		if (value >= min && value < max)
		{
			if (hold[0] == -1)
				hold[0] = i;
			hold[1] = i;
		}
		i++;
	}
}

static void	rotate_to_top_optimized(t_data *data, int hold_first, int hold_sec)
{
	int	rotations;

	if (hold_first <= data->a->size - hold_sec)
	{
		rotations = hold_first;
		while (rotations-- > 0)
			ra(data, 1);
	}
	else
	{
		rotations = data->a->size - hold_sec;
		while (rotations-- > 0)
			rra(data, 1);
	}
}

static void	push_chunk_to_b(t_data *data, int min, int max)
{
	int	count;
	int	value;
	int	hold[2];

	count = max - min;
	while (count > 0 && data->a->size > 3)
	{
		find_hold_values(data, hold, min, max);
		if (hold[0] == -1)
			break ;
		rotate_to_top_optimized(data, hold[0], hold[1]);
		value = get_at_index(data->a, 0);
		pb(data, 1);
		if (value >= min + (max - min) / 2 && data->b->size > 1)
			rb(data, 1);
		count--;
	}
}

static int	find_max_position(t_data *data)
{
	int	i;
	int	max_pos;
	int	max_val;
	int	current;

	if (data->b->size == 0)
		return (-1);
	max_pos = 0;
	max_val = get_at_index(data->b, 0);
	i = 1;
	while (i < data->b->size)
	{
		current = get_at_index(data->b, i);
		if (current > max_val)
		{
			max_val = current;
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

static void	push_back_from_b(t_data *data)
{
	int	pos;

	while (data->b->size > 0)
	{
		pos = find_max_position(data);
		if (pos == -1)
			break ;
		if (pos <= data->b->size / 2)
		{
			while (pos-- > 0)
				rb(data, 1);
		}
		else
		{
			pos = data->b->size - pos;
			while (pos-- > 0)
				rrb(data, 1);
		}
		pa(data, 1);
	}
}

static void	push_to_b_in_chunks(t_data *data)
{
	int	chunk_size;
	int	chunk_start;
	int	total;

	if (data->total_size <= 10)
		chunk_size = 5;
	else if (data->total_size <= 100)
		chunk_size = 20;
	else if (data->total_size <= 200)
		chunk_size = 35;
	else if (data->total_size <= 500)
		chunk_size = 46;
	else
		chunk_size = 55;
	chunk_start = 0;
	total = data->total_size;
	while (chunk_start < total - 3)
	{
		if (chunk_start + chunk_size > total - 3)
			push_chunk_to_b(data, chunk_start, total - 3);
		else
			push_chunk_to_b(data, chunk_start, chunk_start + chunk_size);
		chunk_start += chunk_size;
	}
}

void	improved_quick_sort(t_data *data)
{
	compress_values(data);
	push_to_b_in_chunks(data);
	if (data->a->size <= 3)
		sort_three(data);
	push_back_from_b(data);
}