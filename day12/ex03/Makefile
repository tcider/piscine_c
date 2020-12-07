NAME = ft_hexdump

SRC = *.c

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
