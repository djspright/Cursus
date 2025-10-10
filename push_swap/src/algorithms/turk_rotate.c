/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/10/05 21:57:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_data *data)
{
	int	min_pos;
	int	cost;

	min_pos = find_min_index(data->a);
	cost = get_rotation_cost(min_pos, data->a->size);
	while (cost > 0)
	{
		ra(data, 1);
		cost--;
	}
	while (cost < 0)
	{
		rra(data, 1);
		cost++;
	}
}
