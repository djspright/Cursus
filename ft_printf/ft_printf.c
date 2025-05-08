/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:03:49 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/08 22:03:49 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *format, va_list args)
{
	format++;
	while (*format)
	{
		if (*format == '%')
			char_count('%', 1);
		if (*format == 'c')
			char_count(*format, 1);
		if (*format == 's')
			str_count(*format, 1);
		if (*format == 'i' || *format == 'd')
			decimal_count(*format, 1);
		if (*format == 'u')
			u_decimal_count(*format, 1);
		if (*format == 'x')
			hex_lower_count(*format, 1);
		if (*format == 'X')
			hex_upper_count(*format, 1);
		if (*format == 'p')
			ptr_hex_count(*format, 1);
	}
}

int	ft_printf(const char *format, ...)

{
	va_list args;
	int total_chars;
	if (!format)
		return (-1);
	va_start(args, format);
	total_chars = parse_format(format, args);
	va_end(args);
	return (total_chars);
}
