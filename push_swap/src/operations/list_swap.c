/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 22:00:42 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	temp = stack->head->next->value;
	stack->head->next->value = stack->head->next->next->value;
	stack->head->next->next->value = temp;
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
