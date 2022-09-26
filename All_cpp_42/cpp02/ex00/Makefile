# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 00:26:47 by hesayah           #+#    #+#              #
#    Updated: 2022/05/10 06:21:02 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed00

SRC = srcs/Fixed.cpp \
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