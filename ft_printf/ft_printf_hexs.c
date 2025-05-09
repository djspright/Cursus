/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:16:13 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 03:43:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_hexs(const char *format, va_list args, size_t i)
{
	if (format[i] == 'x')
		return (handle_hex_lower(args));
	else if (format[i] == 'X')
		return (handle_hex_upper(args));
	else if (format[i] == 'p')
		return (handle_pointer(args));
	else
		return (-1);
}
