NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = free_and_close.c init_and_parse_args.c init_data.c monitor.c philo_action.c philo_bonus.c \
		print_message.c time.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re