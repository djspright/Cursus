/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_optimized_quick.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_data *data, int chunk_size)
{
	int	pushed;
	int	rotations;
	int	value;
	int	target;

	pushed = 0;
	target = 0;
	while (pushed < data->total_size - 3 && data->a->size > 3)
	{
		rotations = 0;
		while (rotations < data->a->size && data->a->size > 3)
		{
			value = get_at_index(data->a, 0);
			if (value >= target && value < target + chunk_size)
			{
				pb(data, 1);
				if (data->b->size > 1 && value < target + chunk_size / 2)
					rb(data, 1);
				pushed++;
				rotations = 0;
			}
			else
			{
				ra(data, 1);
				rotations++;
			}
		}
		if (rotations >= data->a->size)
			target += chunk_size;
	}
}

static int	find_target_position(t_data *data, int target)
{
	int	i;
	int	val;

	i = 0;
	while (i < data->b->size)
	{
		val = get_at_index(data->b, i);
		if (val == target)
			return (i);
		i++;
	}
	return (-1);
}

static int	find_next_best(t_data *data, int target)
{
	int	best_pos;
	int	best_val;
	int	i;
	int	val;

	best_pos = -1;
	best_val = -1;
	i = 0;
	while (i < data->b->size)
	{
		val = get_at_index(data->b, i);
		if (val < target && val > best_val)
		{
			best_val = val;
			best_pos = i;
		}
		i++;
	}
	return (best_pos);
}

static void	smart_retrieve(t_data *data)
{
	int	target;
	int	pos;

	target = data->total_size - 1;
	while (data->b->size > 0)
	{
		pos = find_target_position(data, target);
		if (pos == -1)
		{
			pos = find_next_best(data, target);
			if (pos == -1)
				break ;
		}
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
		if (get_at_index(data->a, 0) == target)
			target--;
	}
}

void	optimized_quick_sort(t_data *data)
{
	int	chunk_size;

	compress_values(data);
	if (data->total_size <= 100)
		chunk_size = 20;
	else if (data->total_size <= 300)
		chunk_size = 30;
	else
		chunk_size = 45;
	push_chunks_to_b(data, chunk_size);
	if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 2)
		if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
	smart_retrieve(data);
}