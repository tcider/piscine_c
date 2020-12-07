#include "rush02.h"

char		*detect_point(t_shape *shape, char *res)
{
	int		i;

	i = 0;
	if (shape->c1 == 'A')
	{
		res[i] = '2';
		res[++i] = '3';
		res[++i] = '4';
	}
	else if (shape->c1 == '/')
		res[i] = '1';
	else if (shape->c1 == 'o')
		res[i] = '0';
	else
		return (NULL);
	res[++i] = '\0';
	return (res);
}

char		*detect_col(t_shape *shape, char *res)
{
	int		i;

	i = 0;
	if (shape->c1 == 'A')
	{
		if (shape->c3 == 'C')
		{
			res[i] = '2';
			res[++i] = '4';
		}
		else if (shape->c3 == 'A')
			res[i] = '3';
		else
			return (NULL);
	}
	else if (shape->c1 == '/' && shape->c3 == '\\')
		res[i] = '1';
	else if (shape->c1 == 'o' && shape->c3 == 'o')
		res[i] = '0';
	else
		return (NULL);
	res[++i] = '\0';
	return (res);
}

char		*detect_row(t_shape *shape, char *res)
{
	int		i;

	i = 0;
	if (shape->c1 == 'A')
	{
		if (shape->c2 == 'C')
		{
			res[i] = '3';
			res[++i] = '4';
		}
		else if (shape->c2 == 'A')
			res[i] = '2';
		else
			return (NULL);
	}
	else if (shape->c1 == '/' && shape->c2 == '\\')
		res[i] = '1';
	else if (shape->c1 == 'o' && shape->c2 == 'o')
		res[i] = '0';
	else
		return (NULL);
	res[++i] = '\0';
	return (res);
}

char		*detect_all(t_shape *shape, char *res)
{
	int		i;

	i = 0;
	if (shape->c1 == 'A' && shape->c2 == 'A' && shape->c3 == 'C'
	&& shape->c4 == 'C'	&& shape->row == 'B' && shape->col == 'B')
		res[i] = '2';
	else if (shape->c1 == 'A' && shape->c2 == 'C' && shape->c3 == 'A'
	&& shape->c4 == 'C'	&& shape->row == 'B' && shape->col == 'B')
		res[i] = '3';
	else if (shape->c1 == 'A' && shape->c2 == 'C' && shape->c3 == 'C'
	&& shape->c4 == 'A'	&& shape->row == 'B' && shape->col == 'B')
		res[i] = '4';
	else if (shape->c1 == '/' && shape->c2 == '\\' && shape->c3 == '\\'
	&& shape->c4 == '/'	&& shape->row == '*' && shape->col == '*')
		res[i] = '1';
	else if (shape->c1 == 'o' && shape->c2 == 'o' && shape->c3 == 'o'
	&& shape->c4 == 'o'	&& shape->row == '-' && shape->col == '|')
		res[i] = '0';
	else
		return (NULL);
	res[++i] = '\0';
	return (res);
}

char		*detect_rush(t_shape *shape)
{
	char	*res;
	int		i;
	
	i = 0;
	res = (char*)malloc(sizeof(char) * 4);
	if (shape->x == 1 && shape->y == 1)
		res = detect_point(shape, res);
	else if (shape->x == 1)
		res = detect_col(shape, res);
	else if (shape->y == 1)
		res = detect_row(shape, res);
	else
		res = detect_all(shape, res);
	return (res);
}
