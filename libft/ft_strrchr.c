/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:51:42 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/25 13:07:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
  size_t i;
  size_t len;
  uint8_t *ptr;

  i = 0;
  len = ft_strlen(s);
  ptr = (uint8_t *)s;
  if((char)c == '\0')
    return s;
  while( len - i - 1>= 0)
  {
    if(ptr[len - i - 1] == (char)c)
      return s;
    i++;
  }
  return (void *)s;
}
