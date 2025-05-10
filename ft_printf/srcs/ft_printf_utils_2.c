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

char	*ft_uitoa(unsigned int n)
{
	size_t	i;
	size_t	digits;
	char	*arr;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 10);
	arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[digits] = '\0';
	i = digits - 1;
	while (n != 0)
	{
		arr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (arr);
}

char	*print_hex_lower(unsigned int n)
{
	char	hex_lower[] = "0123456789abcdef";
	size_t	i;
	size_t	base_index;
	size_t	digits;
	char	*arr;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 0x10);
	arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		base_index = get_index((n % 0x10) + '0', hex_lower);
		arr[i] = '0' + hex_lower[base_index];
		n /= 0x10;
		i++;
	}
	arr[digits] = '\0';
	return (arr);
}

char	*print_hex_upper(unsigned int n)
{
	char	hex_upper[] = "0123456789ABCDEF";
	size_t	i;
	size_t	base_index;
	size_t	digits;
	char	*arr;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 0x10);
	arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		base_index = get_index((n % 0x10) + '0', hex_upper);
		arr[i] = '0' + hex_upper[base_index];
		n /= 0x10;
		i++;
	}
	arr[digits] = '\0';
	return (arr);
}

char	*print_pointer(void *addr);
