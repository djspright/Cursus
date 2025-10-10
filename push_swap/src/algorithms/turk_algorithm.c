/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 21:57:12 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_data *data)
{
	pb(data, 1);
	if (data->a->size > 1)
		pb(data, 1);
	while (data->a->size > 3)
		pb(data, 1);
}

static void	find_cheapest_helper(t_data *data, int *ca, int *cb, int min_pos)
{
	int	cost;
	int	min_cost;
	int	cost_a;
	int	cost_b;
	int	i;

	min_cost = 2147483647;
	*ca = 0;
	*cb = 0;
	i = -1;
	while (++i < data->b->size)
	{
		cost_b = get_rotation_cost(i, data->b->size);
		cost_a = get_rotation_cost(find_target_cached(data,
					get_at_index(data->b, i), min_pos), data->a->size);
		cost = calculate_total_cost(cost_a, cost_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			*ca = cost_a;
			*cb = cost_b;
			if (min_cost <= 1)
				break ;
		}
	}
}

static void	find_cheapest(t_data *data, int *ca, int *cb)
{
	int	min_val;
	int	min_pos;

	update_cache(data, &min_val, &min_pos);
	find_cheapest_helper(data, ca, cb, min_pos);
}

static void	push_back_to_a(t_data *data)
{
	int	cost_a;
	int	cost_b;

	while (data->b->size > 0)
	{
		find_cheapest(data, &cost_a, &cost_b);
		execute_double_rotation(data, cost_a, cost_b);
		pa(data, 1);
	}
}

void	turk_sort(t_data *data)
{
	compress_values(data);
	if (data->a->size > 3)
		push_to_b(data);
	if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 2)
		if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
	push_back_to_a(data);
	final_rotate(data);
}
