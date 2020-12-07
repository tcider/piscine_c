#include "ft_brackets.h"

char	open_bracket(char c)
{
	if (c == ')')
		return ('(');
	else if (c == '}')
		return ('{');
	else if (c== ']')
		return ('[');
	else
		return (0);
}

int		check_argv(char *str)
{
	char	buf[BUF_SIZE];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			buf[++j] = str[i];
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (j < 0)
				return (0);
			if (buf[j] == open_bracket(str[i]))
				j--;
			else
				return (0);
		}
	}
	if (j == -1)
		return (1);
	else
		return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc > 1)
		while (++i < argc)
			if (check_argv(argv[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
	else
		write(1, "\n", 1);
	return (0);
}
