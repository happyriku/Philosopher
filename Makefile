TARGET = philo

SRCS = main.c handle_argm_error.c print_error.c action.c get_time.c\
		handle_single_philosopher.c init_info.c handle_philosophers.c print_action.c\

OBJS = $(SRCS:.c=.o)

CC = cc
# CFLAGS = -Wall -Wextra -Werror

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
