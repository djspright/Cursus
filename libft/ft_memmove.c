/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:32:09 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/25 09:47:06 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memmove(void *dst, const void *src, size_t n)
{
  uint8_t *d;
  uint8_t *s;
  size_t i;

  d = (uint8_t *)dst;
  s = (uint8_t *)src;
  i = 0;
  if(d == NULL && s == NULL)
    return NULL;
  if(d < s)
  {
    while(n > 0)
    {
      d[n] = s[n];
    }
  }
  else
{
    while(i < n)
    {
      d[i] = s[i];
      i++;
    }
  }
  return (dst);
}
