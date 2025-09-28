/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:06:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:06:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	if (data->a->size != 3)
		return ;
	first = data->a->array[data->a->head];
	second = data->a->array[(data->a->head + 1) % data->a->capacity];
	third = data->a->array[(data->a->head + 2) % data->a->capacity];
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

void	sort_small(t_data *data)
{
	int	min_idx;
	int	size;

	size = data->a->size;
	while (size > 3 && !is_sorted(data->a))
	{
		min_idx = find_min_index(data->a);
		if (min_idx <= data->a->size / 2)
		{
			while (min_idx > 0)
			{
				ra(data, 1);
				min_idx--;
			}
		}
		else
		{
			while (min_idx < data->a->size)
			{
				rra(data, 1);
				min_idx++;
			}
		}
		pb(data, 1);
		size--;
	}
	if (!is_sorted(data->a))
		sort_three(data);
	while (data->b->size > 0)
		pa(data, 1);
}