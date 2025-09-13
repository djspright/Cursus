# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_username <your_email@student.42.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by your_username    #+#    #+#              #
#    Updated: 2024/01/01 00:00:00 by your_username   ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
NAME_SERVER = server
NAME_CLIENT = client

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(FT_PRINTF) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(GREEN)✅ Minitalk compiled successfully!$(RESET)"

$(NAME_SERVER): $(OBJ_SERVER) $(FT_PRINTF)
	@echo "$(GREEN)🔨 Compiling server...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) -L$(FT_PRINTF_DIR) -lftprintf

$(NAME_CLIENT): $(OBJ_CLIENT) $(FT_PRINTF)
	@echo "$(GREEN)🔨 Compiling client...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) -L$(FT_PRINTF_DIR) -lftprintf

$(FT_PRINTF):
	@echo "$(GREEN)📚 Compiling ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR)

%.o: %.c minitalk.h
	@echo "$(GREEN)🔧 Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -c $< -o $@

clean:
	@echo "$(RED)🗑️  Cleaning object files...$(RESET)"
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)🗑️  Cleaning executables...$(RESET)"
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all
