#include "rush02.h"

t_shape		*shape_size(t_shape *shape, char *str)
{
	int		i;
	int		tmp;
	int		x;
	int		y;

	y = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			y++;
	shape->y = y;
	tmp = -1;
	while (--y >= 0)
	{
		x = 0;
		i = -1;
		while (str[++i] != '\n')
			x++;
		if (tmp != -1 && x != tmp)
			return (NULL);
		tmp = x;
	}
	shape->x = x;
	return (shape);
}

char		shape_row(t_shape *shape, char *str)
{
	int		tmp;
	int		i;

	shape->row = str[shape->x - 2];
	i = 0;
	tmp = 1;
	while (++i < (shape->x - 1))
		if (shape->row != str[i])
			tmp = 0;
	i = (shape->x + 1) * (shape->y - 1);
	while (++i < ((shape->x + 1) * shape->y - 2))
		if (shape->row != str[i])
			tmp = 0;
	if (!tmp)
		return (0);
	return (shape->row);
}

char		shape_col(t_shape *shape, char *str)
{
	int		tmp;
	int		i;

	shape->col = str[shape->x + 1];
	i = shape->x + 1;
	tmp = 1;
	while (i <= ((shape->x + 1) * (shape->y - 1) - shape->x - 1))
	{
		if (shape->col != str[i])
			tmp = 0;
		i += (shape->x + 1);
	}
	i = 2 * shape->x;
	while (i < ((shape->x + 1) * (shape->y - 1) - 1))
	{
		if (shape->col != str[i])
			tmp = 0;
		i += (shape->x + 1);
	}
	if (!tmp)
		return (0);
		return (shape->col);
}

char		shape_field(t_shape *shape, char *str)
{
	int		y;
	int		i;
	int		j;

	y = shape->y;
	if (y > 2)
	{
		j = 2;
		while (j < y)
		{
			i = (j - 1) * (shape->x + 1);
			while (++i <= (j * (shape->x + 1) - 3))
				if (str[i] != ' ')
					return (1);
			j++;
		}
	}
	return (0);
}

t_shape		*shape_struct(char	*str)
{
	t_shape		*shape;

	shape = (t_shape*)malloc(sizeof(t_shape));
	if (!(shape = shape_size(shape, str)) || !(shape->x) || !(shape->y))
		return (NULL);
	shape->c1 = str[0];
	shape->c2 = str[shape->x - 1];
	shape->c3 = str[(shape->x + 1) * (shape->y - 1)];
	shape->c4 = str[(shape->x + 1) * shape->y - 2];
	shape->row = 1;
	shape->col = 1;
	if (shape->x > 2)
		if (!(shape->row = shape_row(shape, str)))
			return (NULL);
	if (shape->y > 2)
		if (!(shape->col = shape_col(shape, str)))
			return (NULL);
	if (shape_field(shape, str))
		return (NULL);
	return (shape);
}
