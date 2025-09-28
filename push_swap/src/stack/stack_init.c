/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:57:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 18:57:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->head = 0;
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

t_data	*data_init(int capacity)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = stack_init(capacity);
	data->b = stack_init(capacity);
	if (!data->a || !data->b)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		free(data);
		return (NULL);
	}
	data->total_size = capacity;
	return (data);
}