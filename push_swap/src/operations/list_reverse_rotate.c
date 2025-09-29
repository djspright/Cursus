/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	last = stack->head->prev;
	stack->head->prev = last->prev;
	last->prev->next = stack->head;
	last->next = stack->head->next;
	last->prev = stack->head;
	stack->head->next->prev = last;
	stack->head->next = last;
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