/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !stack->head)
		return ;
	current = stack->head->next;
	while (current != stack->head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack->head);
	free(stack);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->a)
		stack_free(data->a);
	if (data->b)
		stack_free(data->b);
	free(data);
}