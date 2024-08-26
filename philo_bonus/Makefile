NAME = philo_bonus

SRCS = srcs/action.c \
		srcs/handle_a_philosopher.c \
		srcs/handle_philosophers.c \
		srcs/init_info.c \
		srcs/main.c \
		srcs/output_actions.c \
		srcs/print_error.c \
		srcs/time.c \
		srcs/routine.c \
		srcs/is_valid_input.c \
		srcs/cleanup_info.c \
		utils/ft_atoi.c \
		utils/color.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:all clean fclean re
