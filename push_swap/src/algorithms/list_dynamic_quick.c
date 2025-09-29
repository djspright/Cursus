/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dynamic_quick.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	analyze_distribution(t_data *data)
{
	int		i;
	int		value;
	int		prev_value;
	int		ascending_runs;
	int		descending_runs;

	ascending_runs = 0;
	descending_runs = 0;
	prev_value = get_at_index(data->a, 0);
	i = 1;
	while (i < data->a->size && i < 50)
	{
		value = get_at_index(data->a, i);
		if (value > prev_value)
			ascending_runs++;
		else if (value < prev_value)
			descending_runs++;
		prev_value = value;
		i++;
	}
	if (ascending_runs > descending_runs * 2)
		return (1);
	else if (descending_runs > ascending_runs * 2)
		return (-1);
	return (0);
}

static int	calculate_dynamic_chunk_size(t_data *data)
{
	int	base_size;
	int	distribution;
	int	adjustment;

	if (data->total_size <= 100)
		base_size = 20;
	else if (data->total_size <= 300)
		base_size = 45;
	else if (data->total_size <= 500)
		base_size = 55;
	else
		base_size = 70;
	distribution = analyze_distribution(data);
	adjustment = 0;
	if (distribution > 0)
		adjustment = base_size / 10;
	else if (distribution < 0)
		adjustment = -base_size / 10;
	return (base_size + adjustment);
}

static void	dynamic_push_chunks(t_data *data)
{
	int	chunk_size;
	int	pushed;
	int	rotations;
	int	value;

	chunk_size = calculate_dynamic_chunk_size(data);
	pushed = 0;
	while (pushed < data->total_size - 3 && data->a->size > 3)
	{
		rotations = 0;
		while (rotations < data->a->size && data->a->size > 3)
		{
			value = get_at_index(data->a, 0);
			if (value >= pushed && value < pushed + chunk_size)
			{
				pb(data, 1);
				if (value < pushed + chunk_size / 2)
					rb(data, 1);
				rotations = 0;
			}
			else
			{
				ra(data, 1);
				rotations++;
			}
		}
		pushed += chunk_size;
	}
}

static void	optimized_retrieve(t_data *data)
{
	int		pos;
	int		max_pos;
	int		max_val;
	int		i;
	int		val;

	while (data->b->size > 0)
	{
		max_pos = 0;
		max_val = get_at_index(data->b, 0);
		i = 0;
		while (i < data->b->size)
		{
			val = get_at_index(data->b, i);
			if (val > max_val)
			{
				max_val = val;
				max_pos = i;
			}
			i++;
		}
		pos = max_pos;
		if (pos <= data->b->size / 2)
			while (pos-- > 0)
				rb(data, 1);
		else
		{
			pos = data->b->size - max_pos;
			while (pos-- > 0)
				rrb(data, 1);
		}
		pa(data, 1);
	}
}

void	dynamic_quick_sort(t_data *data)
{
	compress_values(data);
	dynamic_push_chunks(data);
	if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 2)
		if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
	optimized_retrieve(data);
}