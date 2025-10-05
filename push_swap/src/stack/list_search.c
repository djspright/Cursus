/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_second_min_value(t_stack *stack)
{
	int		min_val;
	int		second_min_val;
	t_node	*current;

	min_val = stack->head->next->value;
	second_min_val = INT_MAX;
	current = stack->head->next;
	while (current != stack->head)
	{
		if (current->value < min_val)
		{
			second_min_val = min_val;
			min_val = current->value;
		}
		else if (current->value < second_min_val && current->value != min_val)
			second_min_val = current->value;
		current = current->next;
	}
	return (second_min_val);
}

static int	find_value_index(t_stack *stack, int value)
{
	t_node	*current;
	int		i;

	current = stack->head->next;
	i = 0;
	while (current != stack->head)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

int	find_second_min_index(t_stack *stack)
{
	int	second_min_val;

	if (!stack || !stack->head || stack->size < 2)
		return (-1);
	second_min_val = find_second_min_value(stack);
	return (find_value_index(stack, second_min_val));
}
