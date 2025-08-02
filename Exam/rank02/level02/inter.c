/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:39:35 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/03 02:55:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_appear(char *s, char c)
{
  int i = 0;

  while(s[i])
  {
    if(s[i] == c)
      return 1;
    i++;
  }
  return 0;
}

int main(int ac, char **av)
{
  if(ac == 3)
  {
    int i = 0;
    char used[256] = {0};

    while(av[1][i])
    {
      if(used[av[1][i]] == 0 && is_appear(av[1], av[1][i]) && is_appear(av[2], av[1][i]))
      {
        write(1, &av[1][i], 1);
        used[av[1][i]] = 1;
      }
      i++;
    }
  }
  write(1, "\n", 1);
  return 0;
}
