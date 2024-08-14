TARGET = philo

SRCS = main.c handle_argm_error.c print_error.c action.c get_time.c\
		handle_a_philosopher.c init_info.c handle_philosophers.c classify_by_actions.c\
		color.c routine.c

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
