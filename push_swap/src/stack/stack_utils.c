/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:58:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 20:24:02 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->top <= 0)
		return (1);
	i = stack->top;
	while (i > 0)
	{
		if (stack->array[i] > stack->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min_val;
	int	min_idx;
	int	i;

	if (stack->top < 0)
		return (-1);
	min_val = stack->array[stack->top];
	min_idx = stack->top;
	i = stack->top - 1;
	while (i >= 0)
	{
		if (stack->array[i] < min_val)
		{
			min_val = stack->array[i];
			min_idx = i;
		}
		i--;
	}
	return (stack->top - min_idx);
}

int	find_max_index(t_stack *stack)
{
	int	max_val;
	int	max_idx;
	int	i;

	if (stack->top < 0)
		return (-1);
	max_val = stack->array[stack->top];
	max_idx = stack->top;
	i = stack->top - 1;
	while (i >= 0)
	{
		if (stack->array[i] > max_val)
		{
			max_val = stack->array[i];
			max_idx = i;
		}
		i--;
	}
	return (stack->top - max_idx);
}

static int	find_second_min_value(t_stack *stack)
{
	int	min_val;
	int	second_min_val;
	int	i;

	if (stack->top < 1)
		return (INT_MAX);
	min_val = stack->array[stack->top];
	second_min_val = INT_MAX;
	i = stack->top - 1;
	while (i >= 0)
	{
		if (stack->array[i] < min_val)
		{
			second_min_val = min_val;
			min_val = stack->array[i];
		}
		else if (stack->array[i] < second_min_val && stack->array[i] != min_val)
			second_min_val = stack->array[i];
		i--;
	}
	return (second_min_val);
}

int	find_second_min_index(t_stack *stack)
{
	int	second_min_val;
	int	i;

	if (stack->top < 1)
		return (-1);
	second_min_val = find_second_min_value(stack);
	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == second_min_val)
			return (stack->top - i);
		i--;
	}
	return (-1);
}
