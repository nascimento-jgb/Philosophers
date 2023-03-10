# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 15:21:59 by jonascim          #+#    #+#              #
#    Updated: 2023/03/09 14:36:26 by jonascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)

SRCS = $(wildcard $(SRC_DIR)/*.c)

vpath %.c $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))


all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $@

.PHONY: all clean fclean re bonus
