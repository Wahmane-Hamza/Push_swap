SRCS = push_swap.c push_swap_commands.c push_swap_commands2.c \
						push_swap_commands3.c \
						commands_help.c commands_help2.c \
						algo.c libft.c full_sort.c split.c\

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror 
NAME = push_swap.a
CC = cc
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re