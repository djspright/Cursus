/* ************************************************************************** */

/*                                                                            */

/*                                                        :::      ::::::::   */

/*   ft_printf.c                                        :+:      :+:    :+:   */

/*                                                    +:+ +:+






	+:+     */

/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+






	+#+        */

/*                                                +#+#+#+#+#+






	+#+           */

/*   Created: 2025/05/08 22:03:49 by shkondo           #+#    #+#             */

/*   Updated: 2025/05/08 22:03:49 by shkondo          ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */



#include "ft_printf.h"



int	parse_format(const char *format, va_list args)

{

	size_t i;

	int count;



	i = 0;

	count = 0;

	while (format[i])

	{

		if (format[i] == '%' && format[i + 1])

		{

			i++;

			if (format[i] == 'c')

				handle_char(args);

			else if (format[i] == 's')

				handle_string(args);

			else if (format[i] == '%')

				handle_percent;

			else if (format[i] == 'i' || *format == 'd')

				decimal_count(args);

			else if (format[i] == 'u')

				u_decimal_count(args);

			else if (format[i] == 'x')

				hex_lower_count(args);

			else if (format[i] == 'X')

				hex_upper_count(args);

			else if (format[i] == 'p')

				ptr_hex_count(args);

		}

	}

}



int	ft_printf(const char *format, ...)

{

	va_list args;

	int count;

	if (!format)

		return (-1);

	va_start(args, format);

	count = parse_format(format, args);

	va_end(args);

	return (count);

}
