/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:47:49 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 07:48:05 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_in_range(t_stack *stack, int min, int max)
{
	int	i;
	int	top_dist;
	int	bottom_dist;

	i = 0;
	top_dist = -1;
	bottom_dist = -1;
	while (i <= stack->top)
	{
		if (stack->array[stack->top - i] >= min && stack->array[stack->top
			- i] <= max)
		{
			if (top_dist == -1)
				top_dist = i;
			bottom_dist = stack->top - i + 1;
		}
		i++;
	}
	if (top_dist == -1)
		return (-1);
	if (top_dist <= bottom_dist)
		return (top_dist);
	return (-bottom_dist);
}
