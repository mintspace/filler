# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 12:03:47 by dbubnov           #+#    #+#              #
#    Updated: 2019/08/28 15:50:09 by dbubnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=./resources/players/dbubnov.filler

SRCS=src/*.c

INCLUDES=libft/libft.a

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ all
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

game:
	./resources/filler_vm -f ./resources/maps/map02 -p1 ./resources/players/dbubnov.filler -p2 ./resources/players/superjeannot.filler

run:
	gcc $(FLAGS) ./libft/libft.a ./src/*.c
	./a.out

debug:
	gcc -g $(FLAGS) ./libft/libft.a ./src/*.c

dclean:
	@make -C ./libft/ clean
	rm -Rf a.out.dSYM
	rm a.out
