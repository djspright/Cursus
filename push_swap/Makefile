NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
INCDIR = includes

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/algorithms/small_sort.c \
       $(SRCDIR)/algorithms/compress.c \
       $(SRCDIR)/algorithms/radix_sort.c \
       $(SRCDIR)/parser/input_check.c \
       $(SRCDIR)/parser/error.c \
       $(SRCDIR)/operations/rotate.c \
       $(SRCDIR)/operations/push.c \
       $(SRCDIR)/operations/reverse_rotate.c \
       $(SRCDIR)/operations/swap.c \
       $(SRCDIR)/stack/stack_init.c \
       $(SRCDIR)/stack/stack_utils.c \
       $(SRCDIR)/stack/stack_free.c

BONUS_SRCS = $(SRCDIR)/checker_bonus.c \
             $(SRCDIR)/parser/input_check.c \
             $(SRCDIR)/parser/error.c \
             $(SRCDIR)/operations/rotate.c \
             $(SRCDIR)/operations/push.c \
             $(SRCDIR)/operations/reverse_rotate.c \
             $(SRCDIR)/operations/swap.c \
             $(SRCDIR)/stack/stack_init.c \
             $(SRCDIR)/stack/stack_utils.c \
             $(SRCDIR)/stack/stack_free.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

test: $(NAME)
	./test_push_swap.sh

.PHONY: all bonus clean fclean re test
