# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: metalium <metalium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 12:03:47 by dbubnov           #+#    #+#              #
#    Updated: 2019/08/08 00:32:11 by metalium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

OBJECTS=*.o

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ re

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all


# ./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 players/carli.filler | less
#---------------------------------------------------------

run:
	gcc $(FLAGS) ./libft/libft.a ./src/*.c
	./a.out

debug:
	gcc -g $(FLAGS) ./libft/libft.a ./src/*.c

dclean:
	@make -C ./libft/ clean
	rm -Rf a.out.dSYM
	rm a.out
