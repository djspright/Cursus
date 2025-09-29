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

static void	smart_push_to_b(t_data *data, int min_val, int max_val)
{
	int	count;
	int	value;
	int	mid_val;
	int	rotations;

	count = data->a->size;
	rotations = 0;
	mid_val = (min_val + max_val) / 2;
	while (rotations < count && data->a->size > 3)
	{
		value = get_at_index(data->a, 0);
		if (value >= min_val && value <= max_val)
		{
			pb(data, 1);
			if (data->b->size > 1)
			{
				if (value < mid_val && get_at_index(data->b, 1) > value)
					sb(data, 1);
			}
			rotations = 0;
			count = data->a->size;
		}
		else
		{
			ra(data, 1);
			rotations++;
		}
	}
}

static void	optimized_push_chunks(t_data *data)
{
	int	chunk_size;
	int	i;
	int	min_val;
	int	max_val;
	int	total_pushed;

	if (data->total_size <= 100)
		chunk_size = 20;
	else if (data->total_size <= 500)
		chunk_size = 57;
	else
		chunk_size = 70;
	i = 0;
	total_pushed = 0;
	while (total_pushed < data->total_size - 3 && data->a->size > 3)
	{
		min_val = i * chunk_size;
		max_val = min_val + chunk_size - 1;
		if (max_val >= data->total_size)
			max_val = data->total_size - 1;
		smart_push_to_b(data, min_val, max_val);
		total_pushed = data->total_size - data->a->size;
		i++;
	}
}

static void	find_best_in_b(t_data *data, int *best_pos, int *best_val)
{
	int	i;
	int	val;
	int	cost;
	int	min_cost;

	*best_pos = 0;
	*best_val = get_at_index(data->b, 0);
	min_cost = 1000000;
	i = 0;
	while (i < data->b->size && i < 15)
	{
		val = get_at_index(data->b, i);
		cost = (i <= data->b->size / 2) ? i : data->b->size - i;
		if (val == *best_val + 1)
			cost -= 3;
		if (cost < min_cost || (cost == min_cost && val > *best_val))
		{
			min_cost = cost;
			*best_pos = i;
			*best_val = val;
		}
		i++;
	}
}

static void	improved_push_back(t_data *data)
{
	int	best_pos;
	int	best_val;
	int	last_pushed;

	last_pushed = -1;
	while (data->b->size > 0)
	{
		find_best_in_b(data, &best_pos, &best_val);
		if (best_pos <= data->b->size / 2)
			while (best_pos-- > 0)
				rb(data, 1);
		else
		{
			best_pos = data->b->size - best_pos;
			while (best_pos-- > 0)
				rrb(data, 1);
		}
		pa(data, 1);
		if (data->a->size > 1 && last_pushed != -1 &&
			best_val < last_pushed)
			sa(data, 1);
		last_pushed = best_val;
	}
}

void	improved_quick_sort(t_data *data)
{
	compress_values(data);
	optimized_push_chunks(data);
	if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 2 &&
		get_at_index(data->a, 0) > get_at_index(data->a, 1))
		sa(data, 1);
	improved_push_back(data);
}