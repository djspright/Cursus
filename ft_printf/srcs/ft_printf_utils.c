/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 06:27:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 09:45:16 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	count_digits(unsigned int n, size_t base_len)
{
	size_t			digits;
	unsigned int	num;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		num = -n;
		digits++;
	}
	while (n != 0)
	{
		digits++;
		num /= base_len;
	}
	return (digits);
}

char	*print_hex_lower(unsigned int n)
{
	char			hex_lower[] = "0123456789abcdef";
	size_t			i;
	size_t			digits;
	char			*arr;
	unsigned int	num;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 0x10);
	arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		n /= 0x10;
		i++;
	}
	arr[digits] = '\0';
	return (arr);
}

char	*print_hex_upper(unsigned int n)
{
	char			hex_upper[] = "0123456789ABCDEF";
	size_t			i;
	size_t			digits;
	char			*arr;
	unsigned int	num;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 0x10);
	arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		n /= 0x10;
		i++;
	}
	arr[digits] = '\0';
	return (arr);
}

char	*print_pointer(void *addr);
