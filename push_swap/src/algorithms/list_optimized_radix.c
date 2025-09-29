/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_optimized_radix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int total_size)
{
	if (total_size <= 10)
		return (1);
	else if (total_size <= 100)
		return (4);
	else
		return (8);
}

static void	process_chunk(t_data *data, int min_val, int max_val)
{
	int	count;
	int	value;
	int	mid_val;

	count = data->a->size;
	mid_val = (min_val + max_val) / 2;
	while (count-- > 0)
	{
		value = get_at_index(data->a, 0);
		if (value >= min_val && value <= max_val)
		{
			pb(data, 1);
			if (data->b->size > 1 && value < mid_val)
				rb(data, 1);
		}
		else
			ra(data, 1);
	}
}

static void	push_back_optimized(t_data *data)
{
	int	max_pos;
	int	size;
	int	i;

	while (data->b->size > 0)
	{
		max_pos = 0;
		size = data->b->size;
		if (size == 1)
		{
			pa(data, 1);
			continue ;
		}
		i = 0;
		while (i < size)
		{
			if (get_at_index(data->b, i) > get_at_index(data->b, max_pos))
				max_pos = i;
			i++;
		}
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				rb(data, 1);
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(data, 1);
		}
		pa(data, 1);
	}
}

void	optimized_radix_sort(t_data *data)
{
	int	chunk_size;
	int	chunks;
	int	i;
	int	min_val;
	int	max_val;

	compress_values(data);
	chunk_size = get_chunk_size(data->total_size);
	chunks = (data->total_size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunks && data->a->size > 3)
	{
		min_val = i * chunk_size;
		max_val = (i + 1) * chunk_size - 1;
		if (max_val >= data->total_size)
			max_val = data->total_size - 1;
		process_chunk(data, min_val, max_val);
		i++;
	}
	if (data->a->size <= 3 && data->a->size > 0)
		sort_three(data);
	push_back_optimized(data);
}