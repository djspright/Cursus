/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:49:32 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 03:43:23 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *format, va_list args)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				return (parse_chars(format, args, i));
			else if (format[i] == 'i' || format[i] == 'd' || format[i] == 'u')
				return (parse_decimals(format, args, i));
			else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
				return (parse_hexs(format, args, i));
		}
		i++;
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);
	return (count);
}
