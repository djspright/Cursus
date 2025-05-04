/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:30:11 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 12:11:15 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_lstiter(t_list *lst, void (*f)(void *))
{
  t_list  node;

  if(!lst || !f)
    return ;
  while(lst)
  {
    f(void *);
    lst = lst->next;
  }
  lst->next = NULL;
}
