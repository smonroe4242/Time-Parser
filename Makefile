#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonroe <scmonroe96@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 21:58:39 by smonroe           #+#    #+#              #
#    Updated: 2018/12/28 06:30:45 by smonroe          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = timeparse

SRC = getajob.c

CC = gcc -Wall -Werror -Wextra

LIB = -Llibft -lft

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(SRC) $(LIB) -o $(NAME)

clean:
	make clean -C libft
	/bin/rm -rf *~ \#*\# a.out *.swp *.gch *.o

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME)

re: fclean all

fsan:
	$(CC) $(SRC) $(LIB) -o $(NAME) -g -fsanitize=address

