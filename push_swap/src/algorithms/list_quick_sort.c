/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_data *data, int size)
{
	int	*tmp;
	int	i;
	int	j;
	int	temp;
	int	pivot;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < size)
		tmp[i] = get_at_index(data->a, i);
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (tmp[j] > tmp[j + 1])
			{
				temp = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = temp;
			}
	}
	pivot = tmp[size / 2];
	free(tmp);
	return (pivot);
}

static void	partition_stack(t_data *data, int size, int *pushed)
{
	int	pivot;
	int	i;
	int	value;

	pivot = get_pivot(data, size);
	*pushed = 0;
	i = 0;
	while (i < size)
	{
		value = get_at_index(data->a, 0);
		if (value < pivot)
		{
			pb(data, 1);
			(*pushed)++;
		}
		else
			ra(data, 1);
		i++;
	}
	i = size - *pushed;
	while (i-- > 0 && data->a->size > 3)
		rra(data, 1);
}

static void	quick_sort_a(t_data *data, int size)
{
	int	pushed;

	if (size <= 3)
	{
		if (size == 3)
			sort_three(data);
		else if (size == 2 && get_at_index(data->a, 0) > get_at_index(data->a, 1))
			sa(data, 1);
		return ;
	}
	partition_stack(data, size, &pushed);
	quick_sort_a(data, size - pushed);
	quick_sort_b(data, pushed);
}

void	quick_sort_b(t_data *data, int size)
{
	int	pivot;
	int	pushed;
	int	i;
	int	value;

	if (size <= 1)
	{
		if (size == 1)
			pa(data, 1);
		return ;
	}
	pivot = get_pivot_b(data, size);
	pushed = 0;
	i = 0;
	while (i < size)
	{
		value = get_at_index(data->b, 0);
		if (value >= pivot)
		{
			pa(data, 1);
			pushed++;
		}
		else
			rb(data, 1);
		i++;
	}
	i = size - pushed;
	while (i-- > 0 && data->b->size > 0)
		rrb(data, 1);
	quick_sort_a(data, pushed);
	quick_sort_b(data, size - pushed);
}

void	quick_sort(t_data *data)
{
	compress_values(data);
	quick_sort_a(data, data->a->size);
}