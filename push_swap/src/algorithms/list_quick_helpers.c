/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_quick_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_a(t_data *data)
{
	if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
		sa(data, 1);
}

static void	sort_three_top_a(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = get_at_index(data->a, 0);
	b = get_at_index(data->a, 1);
	c = get_at_index(data->a, 2);
	if (a > b && b > c && a > c)
	{
		sa(data, 1);
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
		if (get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
	}
	else if (a > b && b < c && a > c)
	{
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
	}
	else if (a > b)
		sa(data, 1);
	else if (b > c)
	{
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
		sort_two_a(data);
	}
}

void	handle_small_a(t_data *data, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		sort_two_a(data);
		return ;
	}
	if (size == 3)
	{
		if (data->a->size == 3)
			sort_three(data);
		else
			sort_three_top_a(data);
	}
}

void	handle_small_b(t_data *data, int size)
{
	int	first;
	int	second;

	if (size <= 0)
		return ;
	if (size == 1)
	{
		pa(data, 1);
		return ;
	}
	first = get_at_index(data->b, 0);
	second = get_at_index(data->b, 1);
	if (first < second)
		sb(data, 1);
	pa(data, 1);
	pa(data, 1);
}