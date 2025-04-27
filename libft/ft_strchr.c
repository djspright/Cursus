/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:04:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/25 12:04:59 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
  size_t i;
  uint8_t *ptr;

  ptr = (uint8_t *)s;
  i = 0;
  while(ptr[i])
  {
    if(ptr[i] == c)
      return (uint8_t *)s;
    i++;
  }
  return false;
}
