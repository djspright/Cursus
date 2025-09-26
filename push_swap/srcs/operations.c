/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:38:43 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/21 23:39:34 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int print)
{
	int	temp;

	if (data->a->top < 2)
		return ;
	temp = data->a->array[0];
	data->a->array[0] = data->a->array[1];
	data->a->array[1] = temp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	pa(t_data *data, int print)
{
	int	i;

	if (data->b->top == 0)
		return ;
	i = data->a->top;
	while (i > 0)
	{
		data->a->array[i] = data->a->array[i - 1];
		i--;
	}
	data->a->array[0] = data->b->array[0];
	data->a->top++;
	i = 0;
	while (i < data->b->top - 1)
	{
		data->b->array[i] = data->b->array[i + 1];
		i++;
	}
	data->b->top--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	ra(t_data *data, int print)
{
	int	temp;
	int	i;

	if (data->a->top < 2)
		return ;
	temp = data->a->array[0];
	i = 0;
	while (i < data->a->top - 1)
	{
		data->a->array[i] = data->a->array[i + 1];
		i++;
	}
	data->a->array[data->a->top - 1] = temp;
	if (print)
		ft_putstr_fd("ra\n", 1);
}
