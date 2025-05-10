/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:54:28 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 09:45:23 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_int(int n)
{
	char	*s;

	s = ft_itoa(n);
	return (ft_strlen(s));
}

static int	handle_uint(unsigned int n)
{
	char	*s;

	s = ft_uitoa(n);
	return (ft_strlen(s));
}

int	process_decimals(const char *format, va_list args, size_t i)
{
	if (i == 'i' || i == 'd')
		return (handle_int(args));
	else if (i == 'u')
		return (handle_uint(args));
	else
		return (-1);
}
