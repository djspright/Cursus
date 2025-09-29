/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_top(t_data *data, int pos)
{
	int	size;

	size = data->b->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(data, 1);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(data, 1);
			pos--;
		}
	}
}

static int	find_best_to_push(t_data *data)
{
	int	best_pos;
	int	best_value;
	int	i;
	int	value;

	if (data->b->size == 0)
		return (-1);
	best_pos = 0;
	best_value = get_at_index(data->b, 0);
	i = 1;
	while (i < data->b->size)
	{
		value = get_at_index(data->b, i);
		if (value > best_value)
		{
			best_value = value;
			best_pos = i;
		}
		i++;
	}
	return (best_pos);
}

void	push_back_sorted_from_b(t_data *data)
{
	int	pos;

	while (data->b->size > 0)
	{
		pos = find_best_to_push(data);
		if (pos > 0)
			rotate_b_to_top(data, pos);
		pa(data, 1);
	}
}

void	final_rotation(t_data *data)
{
	int	min_pos;
	int	size;

	min_pos = find_min_index(data->a);
	size = data->a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(data, 1);
			min_pos--;
		}
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos > 0)
		{
			rra(data, 1);
			min_pos--;
		}
	}
}