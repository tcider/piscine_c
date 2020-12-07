#ifndef RUSH02_H
# define RUSH02_H

# define BUF_SIZE 10

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // for test

typedef struct		s_list
{
	int				size;
	char			*data;
	struct s_list	*next;
}					t_list;

typedef	struct		s_shape
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;
	char	row;
	char	col;
	int		x;
	int		y;
}					t_shape;

char		*ft_read_file(int fd);
t_shape		*shape_struct(char *str);
char		*detect_rush(t_shape *shape);

#endif
