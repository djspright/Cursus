/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:08:31 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/12 22:08:37 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char		t_uint8_t;
typedef unsigned short		t_uint16_t;
typedef unsigned int		t_uint32_t;
typedef unsigned long long	t_uint64_t;

# define TRUE 1
# define FALSE 0
# define EOF -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char						*get_next_line(int fd);

void						ft_putchar_fd(char c, int fd);
size_t						ft_strlen(const char *s);
void						ft_putstr_fd(char *s, int fd);
char						*ft_strchr(const char *s, int c);
char						*ft_strdup(const char *s);
char						*ft_substr(const char *s, unsigned int start,
								size_t len);
char						*ft_strjoin(const char *s, const char *s2);

#endif
