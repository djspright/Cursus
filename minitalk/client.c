/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:38:23 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/18 20:20:12 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_exit(ERR_KILL);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_exit(ERR_KILL);
		}
		usleep(1000);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
		error_exit(ERR_ARGS);
	server_pid = ft_atoi_pid(argv[1]);
	if (server_pid <= 0)
		error_exit(ERR_PID);
	i = 0;
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, 0);
	return (0);
}
