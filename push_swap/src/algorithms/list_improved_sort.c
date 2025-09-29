/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_improved_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smart_push_to_b(t_data *data)
{
	int	size;
	int	pushed;
	int	mid_point;
	int	value;

	size = data->a->size;
	pushed = 0;
	mid_point = size / 2;
	while (pushed < size - 3 && data->a->size > 3)
	{
		value = get_at_index(data->a, 0);
		pb(data, 1);
		pushed++;
		if (pushed < mid_point)
		{
			if (value < mid_point / 2 || value > mid_point + mid_point / 2)
				rb(data, 1);
		}
		else
		{
			if (value < mid_point || value > size - size / 4)
				rb(data, 1);
		}
	}
}

static int	find_best_value(t_data *data, int target)
{
	int	best_pos;
	int	best_dist;
	int	i;
	int	val;
	int	dist;

	best_pos = -1;
	best_dist = data->b->size + 1;
	i = 0;
	while (i < data->b->size)
	{
		val = get_at_index(data->b, i);
		if (val == target)
			return (i);
		if (val == target - 1 || val == target + 1)
		{
			dist = (i <= data->b->size / 2) ? i : data->b->size - i;
			if (dist < best_dist)
			{
				best_dist = dist;
				best_pos = i;
			}
		}
		i++;
	}
	return (best_pos);
}

static void	retrieve_with_optimization(t_data *data)
{
	int	target;
	int	pos;
	int	next_pos;
	int	hold;

	target = data->total_size - 1;
	hold = -1;
	while (data->b->size > 0 || hold >= 0)
	{
		if (hold == target)
		{
			target--;
			hold = -1;
			continue ;
		}
		pos = find_best_value(data, target);
		if (pos == -1)
		{
			pos = find_max_pos(data);
			if (pos == -1)
				break ;
		}
		if (data->b->size > 1)
			next_pos = find_best_value(data, target - 1);
		else
			next_pos = -1;
		execute_retrieval(data, pos, &hold, &target);
	}
}

static void	execute_retrieval(t_data *data, int pos, int *hold, int *target)
{
	int	val;

	if (pos <= data->b->size / 2)
		while (pos-- > 0)
			rb(data, 1);
	else
	{
		pos = data->b->size - pos;
		while (pos-- > 0)
			rrb(data, 1);
	}
	val = get_at_index(data->b, 0);
	pa(data, 1);
	if (val == *target)
		(*target)--;
	else if (*hold >= 0 && val > *hold)
	{
		sa(data, 1);
		*hold = val;
	}
	else
		*hold = val;
}

void	improved_sort(t_data *data)
{
	compress_values(data);
	smart_push_to_b(data);
	if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 2)
		if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
	retrieve_with_optimization(data);
}