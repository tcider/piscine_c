# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 08:50:40 by tcider            #+#    #+#              #
#    Updated: 2020/08/05 12:35:53 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

SRC = srcs/main.c

OBJ = main.o

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
