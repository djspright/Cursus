/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;
	int	first_pos;
	int	second_pos;

	if (stack->size < 2)
		return ;
	first_pos = stack->head;
	second_pos = (stack->head + 1) % stack->capacity;
	temp = stack->array[first_pos];
	stack->array[first_pos] = stack->array[second_pos];
	stack->array[second_pos] = temp;
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