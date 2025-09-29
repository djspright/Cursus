/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_advanced_quick.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pivot(t_stack *stack, int size)
{
	int	first;
	int	mid;
	int	last;
	int	quarter;

	if (size <= 3)
		return (get_at_index(stack, size / 2));
	first = get_at_index(stack, 0);
	quarter = get_at_index(stack, size / 4);
	mid = get_at_index(stack, size / 2);
	last = get_at_index(stack, size - 1);
	if ((first <= quarter && quarter <= mid) || (mid <= quarter && quarter <= first))
		return (quarter);
	if ((quarter <= mid && mid <= last) || (last <= mid && mid <= quarter))
		return (mid);
	if ((first <= mid && mid <= last) || (last <= mid && mid <= first))
		return (mid);
	return (quarter);
}

static void	partition_a_optimized(t_data *data, int size, int *p1, int *p2)
{
	int	pivot;
	int	i;
	int	val;

	if (size <= 10)
	{
		*p1 = 0;
		*p2 = 0;
		simple_push_to_b(data, size);
		return ;
	}
	pivot = find_pivot(data->a, size);
	*p1 = 0;
	*p2 = 0;
	i = 0;
	while (i++ < size)
	{
		val = get_at_index(data->a, 0);
		if (val < pivot)
		{
			pb(data, 1);
			(*p1)++;
		}
		else
		{
			ra(data, 1);
			(*p2)++;
		}
	}
}

static void	partition_b_optimized(t_data *data, int size, int *p1, int *p2)
{
	int	pivot;
	int	i;
	int	val;

	pivot = find_pivot(data->b, size);
	*p1 = 0;
	*p2 = 0;
	i = 0;
	while (i++ < size)
	{
		val = get_at_index(data->b, 0);
		if (val >= pivot)
		{
			pa(data, 1);
			(*p1)++;
		}
		else
		{
			rb(data, 1);
			(*p2)++;
		}
	}
}

void	advanced_quick_sort_a(t_data *data, int size, int depth)
{
	int	pushed_b;
	int	rotated;

	if (size <= 3 || depth > 15)
	{
		handle_small_sort_a(data, size);
		return ;
	}
	partition_a_optimized(data, size, &pushed_b, &rotated);
	if (rotated > 0 && data->a->size > rotated)
		while (rotated-- > 0)
			rra(data, 1);
	if (size - pushed_b > 1)
		advanced_quick_sort_a(data, size - pushed_b, depth + 1);
	if (pushed_b > 0)
		advanced_quick_sort_b(data, pushed_b, depth + 1);
}

void	advanced_quick_sort_b(t_data *data, int size, int depth)
{
	int	pushed_a;
	int	rotated;

	if (size <= 0)
		return ;
	if (size <= 3 || depth > 15)
	{
		handle_small_sort_b(data, size);
		return ;
	}
	partition_b_optimized(data, size, &pushed_a, &rotated);
	if (rotated > 0 && data->b->size > rotated)
		while (rotated-- > 0)
			rrb(data, 1);
	if (pushed_a > 0)
		advanced_quick_sort_a(data, pushed_a, depth + 1);
	if (size - pushed_a > 0)
		advanced_quick_sort_b(data, size - pushed_a, depth + 1);
}

void	advanced_quick_sort(t_data *data)
{
	compress_values(data);
	advanced_quick_sort_a(data, data->a->size, 0);
}