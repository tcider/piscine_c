#include "ft_brackets.h"

int		match(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
		return (0);
	else
		return (1);
}

int		ft_check(char *str)
{
	int		i;
	int		j;
	int		buf[BUF];

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (OB(str[i]))
			buf[++j] = str[i];
		if (CB(str[i]))
			if (match(buf[j--], str[i]))
				return (1);
	}
	return (j);
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
		{
			if (!ft_check(argv[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
