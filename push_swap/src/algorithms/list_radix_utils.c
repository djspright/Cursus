/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_radix_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_radix_pass(t_data *data, int bit_pos)
{
	int	i;
	int	value;
	int	total_in_a;

	total_in_a = data->a->size;
	i = 0;
	while (i < total_in_a)
	{
		value = get_at_index(data->a, 0);
		if ((value >> bit_pos) & 1)
			ra(data, 1);
		else
			pb(data, 1);
		i++;
	}
}

int	count_bits_needed(int max_val)
{
	int	bits;

	bits = 0;
	while (max_val > 0)
	{
		bits++;
		max_val >>= 1;
	}
	return (bits);
}

void	smart_push_back(t_data *data)
{
	while (data->b->size > 0)
		pa(data, 1);
}