/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_turk_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/30 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_cache
{
	int	min_val;
	int	min_pos;
}	t_cache;

int		get_rotation_cost(int pos, int size);
int		find_target_pos(t_data *data, int value);
int		calculate_total_cost(int cost_a, int cost_b);
void	execute_double_rotation(t_data *data, int cost_a, int cost_b);

static void	push_to_b(t_data *data)
{
	pb(data, 1);
	if (data->a->size > 1)
		pb(data, 1);
	while (data->a->size > 3)
		pb(data, 1);
}

static void	update_cache(t_data *data, t_cache *cache)
{
	int	i;
	int	cur_val;

	cache->min_pos = 0;
	cache->min_val = get_at_index(data->a, 0);
	i = 1;
	while (i < data->a->size)
	{
		cur_val = get_at_index(data->a, i);
		if (cur_val < cache->min_val)
		{
			cache->min_val = cur_val;
			cache->min_pos = i;
		}
		i++;
	}
}

static int	find_target_cached(t_data *data, int value, t_cache *cache)
{
	int	i;
	int	target;
	int	cur_val;

	target = -1;
	i = 0;
	while (i < data->a->size)
	{
		cur_val = get_at_index(data->a, i);
		if (cur_val > value)
		{
			if (target == -1 || cur_val < get_at_index(data->a, target))
				target = i;
		}
		i++;
	}
	if (target == -1)
		return (cache->min_pos);
	return (target);
}

static void	find_cheapest(t_data *data, int *ca, int *cb)
{
	int		i;
	int		cost;
	int		min_cost;
	int		cost_a;
	int		cost_b;
	t_cache	cache;

	update_cache(data, &cache);
	min_cost = 2147483647;
	*ca = 0;
	*cb = 0;
	i = 0;
	while (i < data->b->size)
	{
		cost_b = get_rotation_cost(i, data->b->size);
		cost_a = get_rotation_cost(find_target_cached(data,
					get_at_index(data->b, i), &cache), data->a->size);
		cost = calculate_total_cost(cost_a, cost_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			*ca = cost_a;
			*cb = cost_b;
			if (min_cost <= 1)
				break;
		}
		i++;
	}
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

static void	final_rotate(t_data *data)
{
	int	min_pos;
	int	cost;

	min_pos = find_min_index(data->a);
	cost = get_rotation_cost(min_pos, data->a->size);
	while (cost > 0)
	{
		ra(data, 1);
		cost--;
	}
	while (cost < 0)
	{
		rra(data, 1);
		cost++;
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