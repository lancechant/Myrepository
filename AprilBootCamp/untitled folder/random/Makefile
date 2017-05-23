# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 09:10:32 by lde-jage          #+#    #+#              #
#    Updated: 2017/03/07 14:43:15 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/*.c

HEADER = $(wildcard includes/*.h)

OUTPUT = *.o

all:
	gcc -c $(HEADER) $(SRC) -Wall -Werror -Wextra -iquoteincludes -g
	gcc $(OUTPUT) -o $(NAME) -Wall -Werror -Wextra -iquoteincludes -g

clean:
	/bin/rm -f *.o
	/bin/rm -f includes/ft.h.gch

fclean:clean
	/bin/rm -f $(NAME)

re: fclean all
