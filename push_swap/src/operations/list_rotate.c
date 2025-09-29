/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:00:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*first;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	first = stack->head->next;
	stack->head->next = first->next;
	first->next->prev = stack->head;
	first->prev = stack->head->prev;
	first->next = stack->head;
	stack->head->prev->next = first;
	stack->head->prev = first;
}

void	ra(t_data *data, int print)
{
	rotate_stack(data->a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data, int print)
{
	rotate_stack(data->b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data, int print)
{
	rotate_stack(data->a);
	rotate_stack(data->b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}