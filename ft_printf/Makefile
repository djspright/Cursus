# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 01:50:30 by shkondo           #+#    #+#              #
#    Updated: 2025/05/08 22:14:04 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
       ft_printf_utils.c \
       ft_printf_chars.c \
       ft_printf_numbers.c \
	   ft_printf_hex.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft

all: $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

libft:
	@$(MAKE) -C $(LIBFT_DIR)
