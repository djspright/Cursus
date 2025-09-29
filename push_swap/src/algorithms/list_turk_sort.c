/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_turk_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_cheapest_position(t_data *data, int value)
{
	int	i;
	int	current;
	int	position;

	position = 0;
	i = 0;
	while (i < data->a->size)
	{
		current = get_at_index(data->a, i);
		if (current > value)
		{
			if (position == 0 || current < get_at_index(data->a, position))
				position = i;
		}
		i++;
	}
	if (position == 0)
	{
		position = find_min_index(data->a);
	}
	return (position);
}

static int	calculate_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	return (cost_a + cost_b);
}

static void	execute_rotation(t_data *data, int pos, char stack)
{
	int	size;

	if (stack == 'a')
		size = data->a->size;
	else
		size = data->b->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (stack == 'a')
				ra(data, 1);
			else
				rb(data, 1);
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			if (stack == 'a')
				rra(data, 1);
			else
				rrb(data, 1);
		}
	}
}

static void	push_with_optimization(t_data *data)
{
	int	chunk_size;
	int	pushed;
	int	i;
	int	value;

	chunk_size = (data->total_size <= 100) ? 30 : 50;
	pushed = 0;
	while (data->a->size > 3)
	{
		i = 0;
		while (i < data->a->size && data->a->size > 3)
		{
			value = get_at_index(data->a, 0);
			if (value <= pushed + chunk_size)
			{
				pb(data, 1);
				if (value <= pushed + chunk_size / 2 && data->b->size > 1)
					rb(data, 1);
				pushed++;
				i = 0;
			}
			else
			{
				ra(data, 1);
				i++;
			}
			if (i >= data->a->size)
			{
				pushed += chunk_size / 2;
				break ;
			}
		}
	}
}

void	turk_sort(t_data *data)
{
	int	best_b_pos;
	int	best_a_pos;
	int	best_cost;
	int	current_cost;
	int	i;

	compress_values(data);
	push_with_optimization(data);
	if (data->a->size <= 3)
		sort_three(data);
	while (data->b->size > 0)
	{
		best_cost = INT_MAX;
		best_b_pos = 0;
		best_a_pos = 0;
		i = 0;
		while (i < data->b->size && i < 20)
		{
			best_a_pos = find_cheapest_position(data, get_at_index(data->b, i));
			current_cost = calculate_cost(best_a_pos, i, data->a->size, data->b->size);
			if (current_cost < best_cost)
			{
				best_cost = current_cost;
				best_b_pos = i;
			}
			i++;
		}
		execute_rotation(data, best_b_pos, 'b');
		best_a_pos = find_cheapest_position(data, get_at_index(data->b, 0));
		execute_rotation(data, best_a_pos, 'a');
		pa(data, 1);
	}
	i = find_min_index(data->a);
	if (i <= data->a->size / 2)
		while (i-- > 0)
			ra(data, 1);
	else
	{
		i = data->a->size - i;
		while (i-- > 0)
			rra(data, 1);
	}
}