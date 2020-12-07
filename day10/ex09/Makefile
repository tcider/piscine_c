NAME = ft_advanced_do-op

SRC = *.c

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
