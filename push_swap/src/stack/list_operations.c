/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack || !stack->head)
		return ;
	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = stack->head->next;
	new_node->prev = stack->head;
	stack->head->next->prev = new_node;
	stack->head->next = new_node;
	stack->size++;
}

void	push_back(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack || !stack->head)
		return ;
	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->prev = stack->head->prev;
	new_node->next = stack->head;
	stack->head->prev->next = new_node;
	stack->head->prev = new_node;
	stack->size++;
}

int	pop_front(t_stack *stack)
{
	t_node	*to_remove;
	int		value;

	if (!stack || !stack->head || stack->size == 0)
		return (0);
	to_remove = stack->head->next;
	value = to_remove->value;
	stack->head->next = to_remove->next;
	to_remove->next->prev = stack->head;
	free(to_remove);
	stack->size--;
	return (value);
}

int	pop_back(t_stack *stack)
{
	t_node	*to_remove;
	int		value;

	if (!stack || !stack->head || stack->size == 0)
		return (0);
	to_remove = stack->head->prev;
	value = to_remove->value;
	stack->head->prev = to_remove->prev;
	to_remove->prev->next = stack->head;
	free(to_remove);
	stack->size--;
	return (value);
}

int	get_at_index(t_stack *stack, int index)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->head || index < 0 || index >= stack->size)
		return (0);
	current = stack->head->next;
	i = 0;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}