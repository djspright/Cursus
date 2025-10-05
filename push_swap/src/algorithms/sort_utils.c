/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 21:59:07 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_data *data, int min_idx)
{
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
		min_idx = data->a->size - min_idx;
		while (min_idx > 0)
		{
			rra(data, 1);
			min_idx--;
		}
	}
}

void	sort_four(t_data *data)
{
	int	min_idx;

	min_idx = find_min_index(data->a);
	rotate_to_top(data, min_idx);
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
}

void	sort_five_optimized(t_data *data)
{
	int	min_idx;

	min_idx = find_min_index(data->a);
	rotate_to_top(data, min_idx);
	pb(data, 1);
	min_idx = find_min_index(data->a);
	rotate_to_top(data, min_idx);
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
	pa(data, 1);
}
