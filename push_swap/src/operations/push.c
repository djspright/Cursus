/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:01:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:01:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data, int print)
{
	if (data->b->size == 0)
		return ;
	data->a->head = (data->a->head - 1 + data->a->capacity) % data->a->capacity;
	data->a->array[data->a->head] = data->b->array[data->b->head];
	data->b->head = (data->b->head + 1) % data->b->capacity;
	data->a->size++;
	data->b->size--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data, int print)
{
	if (data->a->size == 0)
		return ;
	data->b->head = (data->b->head - 1 + data->b->capacity) % data->b->capacity;
	data->b->array[data->b->head] = data->a->array[data->a->head];
	data->a->head = (data->a->head + 1) % data->a->capacity;
	data->b->size++;
	data->a->size--;
	if (print)
		ft_putstr_fd("pb\n", 1);
}