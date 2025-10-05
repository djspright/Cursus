/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 22:02:05 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *from, t_stack *to)
{
	t_node	*to_move;

	if (!from || !to || !from->head || !to->head || from->size == 0)
		return ;
	to_move = from->head->next;
	from->head->next = to_move->next;
	to_move->next->prev = from->head;
	from->size--;
	to_move->next = to->head->next;
	to_move->prev = to->head;
	to->head->next->prev = to_move;
	to->head->next = to_move;
	to->size++;
}

void	pa(t_data *data, int print)
{
	push_stack(data->b, data->a);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data, int print)
{
	push_stack(data->a, data->b);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
