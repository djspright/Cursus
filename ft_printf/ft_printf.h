/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:08:31 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 03:43:24 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		parse_format(const char *format, va_list args);
int		parse_chars(const char *format, va_list args, size_t i);
int		parse_decimals(const char *format, va_list args, size_t i);
int		parse_hexs(const char *format, va_list args, size_t i);

int		handle_char(char c);
int		handle_string(char *s);
int		handle_percent(void);
int		handle_int(int n);
int		handle_uint(unsigned int n);
int		handle_hex_lower(unsigned int n);
int		handle_hex_upper(unsigned int n);
int		handle_pointer(void *ptr);

char	*ft_uitoa(unsigned int n);

#endif
