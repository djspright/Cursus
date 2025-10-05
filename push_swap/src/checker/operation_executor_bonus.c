/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_executor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:31:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 20:31:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	execute_swap_push_ops(t_data *data, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(data, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(data, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(data, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(data, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(data, 0);
	else
		return (0);
	return (1);
}

static int	execute_rotate_ops(t_data *data, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(data, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(data, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(data, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(data, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(data, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(data, 0);
	else
		return (0);
	return (1);
}

int	execute_operation(t_data *data, char *line)
{
	if (execute_swap_push_ops(data, line))
		return (1);
	if (execute_rotate_ops(data, line))
		return (1);
	return (0);
}
