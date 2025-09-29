/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_radix_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorted(t_data *data)
{
	t_node	*current;
	t_node	*next;

	if (data->a->size <= 1)
		return (1);
	current = data->a->head->next;
	while (current->next != data->a->head)
	{
		next = current->next;
		if (current->value > next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	radix_sort(t_data *data)
{
	int	max_bits;
	int	bit_pos;

	compress_values(data);
	max_bits = count_bits_needed(data->total_size - 1);
	bit_pos = 0;
	while (bit_pos < max_bits && !check_sorted(data))
	{
		optimized_radix_pass(data, bit_pos);
		smart_push_back(data);
		bit_pos++;
	}
}