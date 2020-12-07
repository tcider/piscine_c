#include "brainfuck.h"

int		ft_strlen(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	char	*p;
	int		i;
	char	ok;

	if (argc > 1 && ft_strlen(argv[1]) <= LIMIT)
	{
		i = -1;
		p = (char*)malloc(BUF_SIZE * sizeof(char));
		while(++i < BUF_SIZE)
			p[i] = 0;
		i = -1;
		while (argv[1][++i])
		{
			ok = 1;
			if (argv[1][i] == '>')
				p++;
			else if (argv[1][i] == '<')
				p--;
			else if (argv[1][i] == '+')
				(*p)++;
			else if (argv[1][i] == '-')
				(*p)--;
			else if (argv[1][i] == '.')
				write(1, &(*p), 1);
			else if (argv[1][i] == '[' && *p == 0)
				while (ok && ++i)
				{
					if (argv[1][i] == '[')
						ok++;
					else if (argv[1][i] == ']')
						ok--;
				}
			else if (argv[1][i] == ']' && *p)
				while (ok && --i)
				{
					if (argv[1][i] == ']')
						ok++;
					else if (argv[1][i] == '[')
						ok--;
				}
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
