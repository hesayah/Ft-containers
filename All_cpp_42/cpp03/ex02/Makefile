# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 01:54:16 by hesayah           #+#    #+#              #
#    Updated: 2022/05/12 01:55:05 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Frag

SRC = srcs/ClapTrap.cpp \
	srcs/ScavTrap.cpp \
	srcs/FragTrap.cpp \
	srcs/main.cpp

OBJS = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re