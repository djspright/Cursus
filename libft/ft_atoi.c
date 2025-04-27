/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:33:29 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/25 03:45:07 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_space(char c)
{
  if(c >= 9 && c <= 13 || c == 32)
    return true;
  return false;
}

int check_overflow();

int ft_atoi(const char *str)
{
  size_t i;
  int sign;
  int nb;

  i = 0;
  while(str[i] == is_space(str[i]))
    i++;
  if(str[i] == '-' || str[i] == '+')
  {
    if(str[i] == '-')
      sign = -1;
    i++;
  }
  nb = 0;
  while(str[i] >= '0' && str[i] <= '9')
  {
    nb = nb * 10 + (str[i] - '0');
    i++;
  }
  return (nb * sign);
}
