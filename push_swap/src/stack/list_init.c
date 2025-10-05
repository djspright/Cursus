/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 22:02:36 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = create_node(0);
	if (!stack->head)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

t_data	*data_init(int capacity)
{
	t_data	*data;

	(void)capacity;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = stack_init();
	if (!data->a)
	{
		free(data);
		return (NULL);
	}
	data->b = stack_init();
	if (!data->b)
	{
		stack_free(data->a);
		free(data);
		return (NULL);
	}
	data->total_size = 0;
	return (data);
}
