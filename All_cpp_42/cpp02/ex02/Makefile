# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 07:20:43 by hesayah           #+#    #+#              #
#    Updated: 2022/05/10 07:20:50 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed02

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