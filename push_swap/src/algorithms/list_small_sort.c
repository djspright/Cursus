/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->a->size < 2)
		return ;
	if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
		sa(data, 1);
}

static void	sort_three_cases(t_data *data, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(data, 1);
	else if (first > second && second > third && first > third)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (first > second && second < third && first > third)
		ra(data, 1);
	else if (first < second && second > third && first < third)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (first < second && second > third && first > third)
		rra(data, 1);
}

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	if (data->a->size < 2)
		return ;
	if (data->a->size == 2)
	{
		sort_two(data);
		return ;
	}
	first = get_at_index(data->a, 0);
	second = get_at_index(data->a, 1);
	third = get_at_index(data->a, 2);
	sort_three_cases(data, first, second, third);
}

void	sort_small(t_data *data)
{
	int	min_idx;

	if (is_sorted(data->a))
		return ;
	if (data->a->size == 4)
		sort_four(data);
	else if (data->a->size == 5)
		sort_five_optimized(data);
	else
	{
		while (data->a->size > 3 && !is_sorted(data->a))
		{
			min_idx = find_min_index(data->a);
			rotate_to_top(data, min_idx);
			pb(data, 1);
		}
		if (!is_sorted(data->a))
			sort_three(data);
		while (data->b->size > 0)
			pa(data, 1);
	}
}