SRCS = push_swap.c push_swap_commands.c push_swap_commands2.c \
						push_swap_commands3.c \
						commands_help.c commands_help2.c \
						algo.c libft.c full_sort.c split.c

BSRCS = checker_bonus.c push_swap_commands.c push_swap_commands2.c \
						push_swap_commands3.c \
						commands_help.c commands_help2.c \
						algo.c libft.c full_sort.c split.c\
						get_next_line_bonus.c get_next_line_utils_bonus.c 

OBJS = $(SRCS:%.c=%.o)

BOBJS = $(BSRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror 
NAME = push_swap
BNAME = checker
CC = cc
RM = rm -f

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)


$(BNAME): $(BOBJS)
	$(CC) $(FLAGS) $(BOBJS) -o $(BNAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all bonus

.PHONY: all clean fclean re