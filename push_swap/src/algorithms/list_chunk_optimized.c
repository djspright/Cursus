/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chunk_optimized.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks(t_data *data, int chunk_size)
{
	int	chunk;
	int	rotations;
	int	value;

	chunk = 0;
	while (data->a->size > 3)
	{
		rotations = 0;
		while (rotations < data->a->size && data->a->size > 3)
		{
			value = get_at_index(data->a, 0);
			if (value >= chunk * chunk_size && value < (chunk + 1) * chunk_size)
			{
				pb(data, 1);
				if (value < chunk * chunk_size + chunk_size / 2)
					rb(data, 1);
				rotations = 0;
			}
			else
			{
				ra(data, 1);
				rotations++;
			}
		}
		if (rotations >= data->a->size)
			chunk++;
	}
}

static int	get_max_pos(t_data *data)
{
	int	max_pos;
	int	max_val;
	int	i;
	int	val;

	if (data->b->size == 0)
		return (-1);
	max_pos = 0;
	max_val = get_at_index(data->b, 0);
	i = 1;
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
	return (max_pos);
}

static void	push_back_sorted(t_data *data)
{
	int	pos;

	while (data->b->size > 0)
	{
		pos = get_max_pos(data);
		if (pos == -1)
			break;
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

void	chunk_optimized_sort(t_data *data)
{
	int	chunk_size;

	compress_values(data);
	if (data->total_size <= 100)
		chunk_size = 20;
	else if (data->total_size <= 500)
		chunk_size = 47;
	else
		chunk_size = 70;
	push_chunks(data, chunk_size);
	if (data->a->size <= 3)
		sort_three(data);
	push_back_sorted(data);
}