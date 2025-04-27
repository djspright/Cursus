/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:22:51 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/25 03:25:04 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
  u_int8_t *d;
  const u_int8_t *s = (const u_int8_t *)src;

  d = (u_int8_t *)dst;
  while(n--)
    *d++ = *s++;
  return (dst);
}
