/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:02:30 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/25 10:02:30 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	uint8_t	*ptr;
	uint8_t	uc;

	i = 0;
	ptr = (uint8_t *)s;
	uc = (uint8_t)c;
	while (ptr[i] != '\0' && i < n)
	{
		if (ptr[i] == uc)
			return ((uint8_t *)s);
		i++;
	}
	return (NULL);
}
