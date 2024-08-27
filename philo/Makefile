NAME = philo

SRCS = srcs/main.c \
		srcs/handle_argm_error.c \
		srcs/print_error.c \
		srcs/action.c \
		srcs/time.c \
		srcs/handle_a_philosopher.c \
		srcs/info_init.c \
		srcs/handle_philosophers.c \
		srcs/classify_by_actions.c \
		srcs/color.c \
		srcs/routine.c \
		srcs/mutex_destroy.c \
		srcs/monitor_threads.c \
		srcs/ft_atoi.c \

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
