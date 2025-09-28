/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:03:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:03:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	stack->head = (stack->head - 1 + stack->capacity) % stack->capacity;
}

void	rra(t_data *data, int print)
{
	reverse_rotate_stack(data->a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data, int print)
{
	reverse_rotate_stack(data->b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data, int print)
{
	reverse_rotate_stack(data->a);
	reverse_rotate_stack(data->b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}