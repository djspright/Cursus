/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_final_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int total)
{
	if (total <= 100)
		return (20);
	else if (total <= 500)
		return (45);
	return (100);
}

static void	push_chunks_to_b(t_data *data)
{
	int	chunk_size;
	int	chunk_index;
	int	count;
	int	i;
	int	val;

	chunk_size = get_chunk_size(data->total_size);
	chunk_index = 0;
	while (data->a->size > 0)
	{
		count = 0;
		i = 0;
		while (i < data->a->size && data->a->size > 0)
		{
			val = get_at_index(data->a, 0);
			if (val >= chunk_index && val < chunk_index + chunk_size)
			{
				pb(data, 1);
				if (data->b->size > 1 && val < chunk_index + chunk_size / 2)
					rb(data, 1);
				count++;
				i = 0;
			}
			else
			{
				ra(data, 1);
				i++;
			}
		}
		if (count == 0)
			chunk_index += chunk_size;
		if (chunk_index >= data->total_size)
			break;
	}
}

static void	push_back_from_b(t_data *data)
{
	int	target;
	int	pos;
	int	i;
	int	val;

	target = data->total_size - 1;
	while (data->b->size > 0 && target >= 0)
	{
		pos = -1;
		i = 0;
		while (i < data->b->size)
		{
			val = get_at_index(data->b, i);
			if (val == target)
			{
				pos = i;
				break;
			}
			i++;
		}
		if (pos != -1)
		{
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
			target--;
		}
		else
			target--;
	}
}

void	final_sort(t_data *data)
{
	compress_values(data);
	if (is_sorted(data->a))
		return;
	push_chunks_to_b(data);
	push_back_from_b(data);
}