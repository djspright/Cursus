/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:38:29 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/13 22:40:02 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

int	ft_atoi_pid(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!str || !str[0])
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || result <= 0)
		return (-1);
	return (result);
}
