# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 04:05:31 by shkondo           #+#    #+#              #
#    Updated: 2025/05/13 04:05:41 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c \
       get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
HEADER = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
