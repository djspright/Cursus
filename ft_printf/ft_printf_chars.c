/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:19:20 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/08 22:20:16 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
	return (1);
}

int	handle_string(char *s)
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

int	handle_prtcent(void)
{
	write(STDOUT_FILENO, "%", sizeof(char));
	return (1);
}
