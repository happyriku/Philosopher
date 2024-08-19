TARGET = philo

SRCS = main.c handle_argm_error.c print_error.c action.c time.c\
		handle_a_philosopher.c info_init.c handle_philosophers.c classify_by_actions.c\
		color.c routine.c mutex_destroy.c monitor_threads.c ft_atoi.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -O0

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY:all clean fclean re
