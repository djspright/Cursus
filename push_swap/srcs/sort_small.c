/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:39:28 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/21 23:39:32 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (data->a->top != 3)
		return ;
	a = data->a->array[0];
	b = data->a->array[1];
	c = data->a->array[2];
	if (a > b && b < c && a < c)
		sa(data, 1);
	else if (a > b && b > c)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (a > b && b < c && a > c)
		ra(data, 1);
	else if (a < b && b > c && a < c)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (a < b && b > c && a > c)
		rra(data, 1);
}

void	sort_small(t_data *data)
{
	int	min_index;
	int	moves;

	while (data->a->top > 3)
	{
		min_index = find_min_index(data->a);
		moves = min_index;
		if (moves > data->a->top / 2)
		{
			moves = data->a->top - moves;
			while (moves-- > 0)
				rra(data, 1);
		}
		else
		{
			while (moves-- > 0)
				ra(data, 1);
		}
		pb(data, 1);
	}
	sort_three(data);
	while (data->b->top > 0)
		pa(data, 1);
}
