/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_advanced_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_push_to_b(t_data *data, int size)
{
	int	min_idx;
	int	i;
	int	j;
	int	min_val;
	int	val;

	i = 0;
	while (i < size && data->a->size > 3)
	{
		min_idx = 0;
		min_val = get_at_index(data->a, 0);
		j = 1;
		while (j < data->a->size && j < size - i)
		{
			val = get_at_index(data->a, j);
			if (val < min_val)
			{
				min_val = val;
				min_idx = j;
			}
			j++;
		}
		while (min_idx-- > 0)
			ra(data, 1);
		pb(data, 1);
		i++;
	}
}

static void	sort_three_in_a(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (data->a->size < 3)
		return ;
	a = get_at_index(data->a, 0);
	b = get_at_index(data->a, 1);
	c = get_at_index(data->a, 2);
	if (a > b && b > c)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (a > c && c > b)
		ra(data, 1);
	else if (b > a && a > c)
		rra(data, 1);
	else if (b > c && c > a)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (c > a && a > b)
		sa(data, 1);
}

void	handle_small_sort_a(t_data *data, int size)
{
	if (size <= 1 || is_sorted(data->a))
		return ;
	if (size == 2)
	{
		if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
		return ;
	}
	if (data->a->size == 3)
	{
		sort_three_in_a(data);
		return ;
	}
	simple_push_to_b(data, size - 3);
	if (data->a->size == 3)
		sort_three_in_a(data);
	while (data->b->size > 0)
		pa(data, 1);
}

void	handle_small_sort_b(t_data *data, int size)
{
	int	max_idx;
	int	i;
	int	j;
	int	max_val;
	int	val;

	if (size <= 0)
		return ;
	i = 0;
	while (i < size && data->b->size > 0)
	{
		max_idx = 0;
		max_val = get_at_index(data->b, 0);
		j = 1;
		while (j < data->b->size && j < size - i)
		{
			val = get_at_index(data->b, j);
			if (val > max_val)
			{
				max_val = val;
				max_idx = j;
			}
			j++;
		}
		while (max_idx-- > 0)
			rb(data, 1);
		pa(data, 1);
		i++;
	}
}