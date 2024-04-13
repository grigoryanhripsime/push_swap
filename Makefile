CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCS)

SRCS = push_swap.c ft_split.c errors.c valid.c initialize.c swap.c push.c rotate.c rev_rotate.c indexes.c sorting.c butterfly.c log.c

BONUS_SRCS = get_next_line.c get_next_line_utils.c checker.c ft_split.c errors.c valid.c initialize.c swap.c push.c rotate.c rev_rotate.c indexes.c checker_utils.c sorting.c

INCS = ./

NAME = push_swap

BONUS_NAME = checker

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) Makefile push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS) Makefile push_swap.h get_next_line.h
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean 
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all fclean clean re bonus
