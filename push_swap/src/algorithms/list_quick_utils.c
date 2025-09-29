/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_quick_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:30:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/29 10:30:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot_b(t_data *data, int size)
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
		tmp[i] = get_at_index(data->b, i);
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

void	sort_top_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (data->a->size < 2)
		return ;
	a = get_at_index(data->a, 0);
	b = get_at_index(data->a, 1);
	if (data->a->size == 2)
	{
		if (a > b)
			sa(data, 1);
		return ;
	}
	c = get_at_index(data->a, 2);
	if (a > b && a > c && b > c)
	{
		sa(data, 1);
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
		sa(data, 1);
	}
	else if (a > b && a > c)
	{
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
	}
	else if (a > b)
		sa(data, 1);
	else if (b > c && a > c)
	{
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
		sa(data, 1);
	}
}

static int	find_median_of_three(int a, int b, int c)
{
	if ((a >= b && a <= c) || (a >= c && a <= b))
		return (a);
	if ((b >= a && b <= c) || (b >= c && b <= a))
		return (b);
	return (c);
}

int	get_smart_pivot(t_data *data, t_stack *stack, int size)
{
	int	first;
	int	middle;
	int	last;

	(void)data;
	if (size <= 3)
		return (get_at_index(stack, size / 2));
	first = get_at_index(stack, 0);
	middle = get_at_index(stack, size / 2);
	last = get_at_index(stack, size - 1);
	return (find_median_of_three(first, middle, last));
}