/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:08:31 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/07 21:24:33 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	char_count(char c, int fd);
int	str_count(char *s, int fd);
int	decimal_count(int n, int fd);
int	hex_lower_count(unsigned int n, int fd);
int	hex_upper_count(unsigned int n, int fd);
int	ptr_hex_count(void *ptr, int fd);
int	u_decimal_count(unsigned int n, int fd);

#endif
