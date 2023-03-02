NAME = philo
CC = cc
CFLAGS = -Werror -Wall -Wextra
COMFILE_FLAGS = -g -pthread -fsanitize=address

MAIN_SRCS =  $(addprefix srcs/, main.c parameters.c philo.c routine.c utils.c)

MAIN_OBJS = $(MAIN_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MAIN_OBJS)
	@$(CC) $(CFLAGS) $(COMFILE_FLAGS) $(MAIN_OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(MAIN_OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
