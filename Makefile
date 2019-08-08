# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 12:03:47 by dbubnov           #+#    #+#              #
#    Updated: 2019/08/07 20:44:02 by dbubnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=filler.a
SRCS=src/*.c
OBJECTS=*.o
INCLUDES=src/
FLAGS=-Werror -Wextra -Wall
all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc $(FLAGS) -I$(INCLUDES) -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all



// ./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 players/carli.filler | less
