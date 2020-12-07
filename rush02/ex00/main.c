#include "rush02.h"

void		print_result(char *res, int x, int y) //FIXME
{
	while (*res)
	{
		printf("%c - %d - %d\n", *res, x, y);
		res++;
	}
}

int			main(void)
{
	char		*str;
	t_shape		*shape;
	char		*res;

	str = ft_read_file(0);
	if (str && str[0])
	{
		if ((shape = shape_struct(str)))
		{
			if ((res = detect_rush(shape)))
				print_result(res, shape->x, shape->y);
			else
				write(1, "Error\n", 6);
			free(res);
		}
		else
			write(1, "Error\n", 6);
		free(shape);
	}
	else
		write(1, "Error\n", 6);
	free(str);
	return (0);
}
