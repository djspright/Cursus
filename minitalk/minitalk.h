/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:38:01 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/13 22:51:12 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/srcs/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_ARGS "Usage: ./client <server_pid> <message>\n"
# define ERR_PID "Invalid PID\n"
# define ERR_KILL "Kill failed\n"

void	error_exit(char *msg);
int		ft_atoi_pid(const char *str);

#endif
