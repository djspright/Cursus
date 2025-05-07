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
/*   Created: 2025/05/06 16:22:25 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/06 16:22:46 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	ft_putchar(char c, fd)
{
	return (write(fd, &c, sizeof(char)));
}

int	str_count(char *s, fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	parse_input(char *format, vargs)
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

int	ft_printf(const char *ristrict format, ...)
{
	va_list vargs;
	va_start(vargs, (char *)format);
	int parse_flag(char *format);
	va_end(vargs);
}

int	main(void)
{
	// ft_printf("%c", 'c');
	// ft_printf("%%");
	printf("%c", 'c');
	printf("%%");
}
