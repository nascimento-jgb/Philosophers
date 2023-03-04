NAME = philo
NAMEBONUS = philo_bonus
CC = cc
CFLAGS = -Werror -Wall -Wextra -I includes
COMPILE_FLAGS = -g -pthread

MAIN_SRCS =  $(addprefix philo/srcs/, main.c parameters.c philosophers.c routine.c utils.c)
BONUS_SRCS = $(addprefix philo_bonus/srcs/, main.c parameters.c philosophers.c routine.c utils.c)

MAIN_OBJS = $(MAIN_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MAIN_OBJS)
	@$(CC) $(CFLAGS) $(COMPILE_FLAGS) $(MAIN_OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAMEBONUS) : $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(COMPILE_FLAGS) $(BONUS_OBJS) -o $(NAMEBONUS)

bonus: $(NAMEBONUS)
	ar rus $(NAME) $(BONUS_OBJS:.c=.o)

clean :
	@rm -rf $(MAIN_OBJS) $(BONUS_OBJS)

fclean : clean
	@rm -rf $(NAME) $(NAMEBONUS)

re : fclean all

.PHONY : all clean fclean re
