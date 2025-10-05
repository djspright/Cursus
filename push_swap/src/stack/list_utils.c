/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 22:02:58 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head || stack->size <= 1)
		return (1);
	current = stack->head->next;
	while (current->next != stack->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		min_idx;
	int		i;

	if (!stack || !stack->head || stack->size == 0)
		return (-1);
	current = stack->head->next;
	min_node = current;
	min_idx = 0;
	i = 0;
	while (current != stack->head)
	{
		if (current->value < min_node->value)
		{
			min_node = current;
			min_idx = i;
		}
		current = current->next;
		i++;
	}
	return (min_idx);
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;
	int		max_idx;
	int		i;

	if (!stack || !stack->head || stack->size == 0)
		return (-1);
	current = stack->head->next;
	max_node = current;
	max_idx = 0;
	i = 0;
	while (current != stack->head)
	{
		if (current->value > max_node->value)
		{
			max_node = current;
			max_idx = i;
		}
		current = current->next;
		i++;
	}
	return (max_idx);
}
