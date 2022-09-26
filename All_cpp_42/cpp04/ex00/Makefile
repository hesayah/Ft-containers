# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 05:48:19 by hesayah           #+#    #+#              #
#    Updated: 2022/05/12 13:19:40 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SRC = srcs/Animal.cpp \
	srcs/Cat.cpp \
	srcs/Dog.cpp \
	srcs/WrongAnimal.cpp \
	srcs/WrongCat.cpp \
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