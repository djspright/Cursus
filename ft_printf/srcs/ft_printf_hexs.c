/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:16:13 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 09:45:24 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	handle_hex_lower(unsigned int n)
{
	char	*s;

	s = print_hex_lower(n);
	return (ft_strlen(s));
}

static int	handle_hex_upper(unsigned int n)
{
	char	*s;

	s = print_hex_upper(n);
	return (ft_strlen(s));
}

static int	handle_pointer(void *ptr)
{
	char	*s;

	s = print_pointer(ptr);
	return (ft_strlen(s));
}

int	process_hexs(const char *format, va_list args, size_t i)
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
