/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 01:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 07:44:39 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_top(t_data *data, int pos)
{
	int	size;

	size = data->b->top + 1;
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
	int	i;
	int	best_pos;
	int	max_val;

	if (data->b->top < 0)
		return (-1);
	best_pos = 0;
	max_val = data->b->array[data->b->top];
	i = 1;
	while (i <= data->b->top)
	{
		if (data->b->array[data->b->top - i] > max_val)
		{
			best_pos = i;
			max_val = data->b->array[data->b->top - i];
		}
		i++;
	}
	return (best_pos);
}

void	push_back_sorted_from_b(t_data *data)
{
	int	pos;

	while (data->b->top >= 0)
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
	size = data->a->top + 1;
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

