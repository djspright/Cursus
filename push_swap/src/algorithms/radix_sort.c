/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:08:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 19:08:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((1 << max_bits) < size)
		max_bits++;
	return (max_bits);
}

static int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}

void	sort_large(t_data *data)
{
	int	max_bits;
	int	bit_pos;
	int	size;
	int	i;

	compress_values(data);
	max_bits = get_max_bits(data->a->size);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		size = data->a->size;
		i = 0;
		while (i < size)
		{
			if (get_bit(data->a->array[data->a->head], bit_pos) == 0)
				pb(data, 1);
			else
				ra(data, 1);
			i++;
		}
		while (data->b->size > 0)
			pa(data, 1);
		bit_pos++;
	}
}