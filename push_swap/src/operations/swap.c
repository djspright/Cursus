/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 20:23:05 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return ;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
}

void	sa(t_data *data, int print)
{
	swap_stack(data->a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data, int print)
{
	swap_stack(data->b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data, int print)
{
	swap_stack(data->a);
	swap_stack(data->b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
