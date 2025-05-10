/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:19:20 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 03:43:22 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_char(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
	return (1);
}

static int	handle_string(char *s)
{
	int	len;

	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}

static int	handle_percent(void)
{
	write(STDOUT_FILENO, "%", sizeof(char));
	return (1);
}

int	process_chars(const char *format, va_list args, size_t i)
{
	if (format[i] == 'c')
		return (handle_char(args));
	else if (format[i] == 's')
		return (handle_string(args));
	else if (format[i] == '%')
		return (handle_percent());
	else
		return (-1);
}
