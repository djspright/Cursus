/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:02:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:02:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	stack->head = (stack->head + 1) % stack->capacity;
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