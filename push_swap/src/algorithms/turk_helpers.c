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

int	get_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	find_target_pos(t_data *data, int value)
{
	int	i;
	int	target;
	int	min_pos;
	int	min_val;
	int	cur_val;

	min_pos = 0;
	min_val = get_at_index(data->a, 0);
	target = -1;
	i = 0;
	while (i < data->a->size)
	{
		cur_val = get_at_index(data->a, i);
		if (cur_val < min_val)
		{
			min_val = cur_val;
			min_pos = i;
		}
		if (cur_val > value)
		{
			if (target == -1 || cur_val < get_at_index(data->a, target))
				target = i;
		}
		i++;
	}
	if (target == -1)
		return (min_pos);
	return (target);
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = (cost_a < 0) ? -cost_a : cost_a;
	abs_b = (cost_b < 0) ? -cost_b : cost_b;
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

void	execute_double_rotation(t_data *data, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(data, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(data, 1);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(data, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(data, 1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(data, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(data, 1);
		cost_b++;
	}
}