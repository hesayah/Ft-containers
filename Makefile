# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 00:47:45 by hesayah           #+#    #+#              #
#    Updated: 2022/11/15 01:29:29 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = c++

NAME = FT_containers

NAME_STD = STD_containers

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME) $(NAME_STD)
$(NAME): 
	$(GCC) $(FLAGS) main.cpp -D ft=ft -o $(NAME) 

$(NAME_STD): 
	$(GCC) $(FLAGS) main.cpp -o $(NAME_STD)

fclean : 
	@rm -f $(NAME) $(NAME_STD)
	@rm one two moulinette

re : fclean all

test : all
	./FT_containers seed > one 
	./STD_containers seed > two 
	diff one two > moulinette

max_test :
	git clone git@github.com:mli42/containers_test.git
	cd containers_test && ./do.sh
	@rm -rf containers_test

.PHONY: re fclean all test max_test
