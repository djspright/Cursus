# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 01:50:30 by shkondo           #+#    #+#              #
#    Updated: 2025/05/10 06:10:24 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS_DIR = srcs

SRC_FILES_NAMES = ft_printf \
                  ft_printf_utils \
                  ft_printf_chars \
                  ft_printf_decimals \
                  ft_printf_hexs

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(SRC_FILES_NAMES)))

OBJS = $(addsuffix .o, $(SRC_FILES_NAMES))

INCLUDES = -I$(SRCS_DIR) -I$(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft

all: $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	@echo "Creating $(NAME)..."
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) created successfully!"

%.o: $(SRCS_DIR)/%.c $(SRCS_DIR)/ft_printf.h $(LIBFT_DIR)/libft.h
	@echo "Compiling $< -> $@..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	@echo "All cleaned."

re: fclean all

libft:
	@$(MAKE) -C $(LIBFT_DIR)

# test: all
# 	$(CC) $(CFLAGS) $(INCLUDES) srcs/main.c -o main.o
# 	$(CC) main.o -L. -lftprintf -L$(LIBFT_DIR) -lft -o test_printf
# 	@echo "Run ./test_printf to test."

# run: test
# 	./test_printf
