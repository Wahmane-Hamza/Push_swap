SRCS = push_swap.c push_swap_commands.c push_swap_commands2.c \
						push_swap_commands3.c \
						commands_help.c commands_help2.c \
						algo.c libft.c full_sort.c split.c\

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror 
NAME = push_swap
CC = cc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re