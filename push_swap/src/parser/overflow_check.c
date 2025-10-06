/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:05:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 20:25:54 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	get_sign(const char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

int	check_int_overflow(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = get_sign(&str[i]);
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && result > (long)INT_MAX + 1)
			return (0);
		i++;
	}
	return (1);
}
