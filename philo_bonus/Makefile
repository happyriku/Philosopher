NAME = philo_bonus

SRCS = action.c ft_atoi.c handle_a_philosopher.c handle_philosophers.c handle_args_error.c\
		info_init.c main.c output_actions.c print_error.c time.c color.c routine.c\

OBJS = $(SRCS:.c=.o)

CC = cc
# CFLAGS =

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

.c.o:
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:all clean fclean re