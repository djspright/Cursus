/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 01:47:04 by shkondo           #+#    #+#             */
/*   Updated: 2025/07/19 01:52:13 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 4)
	{
		if (av[2][1] == '\0' && av[3][1] == '\0')
		{
			while (av[1][i] != '\0')
			{
				if (av[1][i] == av[2][0])
					write(1, &av[3][0], 1);
				else
					write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
