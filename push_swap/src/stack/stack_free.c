/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 20:25:06 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->array)
		free(stack->array);
	free(stack);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	stack_free(data->a);
	stack_free(data->b);
	free(data);
}
