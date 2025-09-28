/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:58:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 18:58:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;
	int	prev;
	int	curr;

	if (stack->size <= 1)
		return (1);
	prev = stack->array[stack->head];
	i = 1;
	while (i < stack->size)
	{
		curr = stack->array[(stack->head + i) % stack->capacity];
		if (prev > curr)
			return (0);
		prev = curr;
		i++;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min_val;
	int	min_idx;
	int	i;
	int	val;

	if (stack->size == 0)
		return (-1);
	min_val = stack->array[stack->head];
	min_idx = 0;
	i = 1;
	while (i < stack->size)
	{
		val = stack->array[(stack->head + i) % stack->capacity];
		if (val < min_val)
		{
			min_val = val;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	find_max_index(t_stack *stack)
{
	int	max_val;
	int	max_idx;
	int	i;
	int	val;

	if (stack->size == 0)
		return (-1);
	max_val = stack->array[stack->head];
	max_idx = 0;
	i = 1;
	while (i < stack->size)
	{
		val = stack->array[(stack->head + i) % stack->capacity];
		if (val > max_val)
		{
			max_val = val;
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}