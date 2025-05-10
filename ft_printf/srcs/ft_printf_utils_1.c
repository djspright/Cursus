/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:43:44 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 09:44:37 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_index(char c, char *base)
{
	size_t	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	count_digits(int n, size_t base_len)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= base_len;
	}
	return (digits);
}

