# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 16:55:38 by shkondo           #+#    #+#              #
#    Updated: 2025/09/13 17:16:59 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname -s)

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2

SRCDIR = src
INCDIR = include
OBJDIR = obj
LIBFT_DIR = libft

ifeq ($(UNAME), Darwin)
    MLX_DIR = minilibx_opengl_20191021
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
    INCLUDES = -I$(INCDIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
else ifeq ($(UNAME), Linux)
    MLX_DIR = minilibx-linux
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
    INCLUDES = -I$(INCDIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
else
    $(error Unsupported OS: $(UNAME))
endif

LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully for $(UNAME)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo "🔧 Building libft..."
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "🔧 Building MiniLibX for $(UNAME)..."
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT_DIR) clean
	@if [ -d $(MLX_DIR) ]; then make -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

debug:
	@echo "OS: $(UNAME)"
	@echo "MLX_DIR: $(MLX_DIR)"
	@echo "MLX_FLAGS: $(MLX_FLAGS)"
	@echo "INCLUDES: $(INCLUDES)"

.PHONY: all clean fclean re debug
