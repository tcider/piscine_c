#include "ft_brainfuck.h"

int		str_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void		ft_brainfuck(char *buf, char *com)
{
	int		i; 
	int		j;
	int		ok;

	i = -1;
	j = 0;
	while (++i < str_size(com))
	{
		ok = 1;
		if (com[i] == '>')
			j++;
		else if (com[i] == '<')
			j--;
		else if (com[i] == '+')
			buf[j]++;
		else if (com[i] == '-')
			buf[j]--;
		else if (com[i] == '.')
			write(1, &(buf[j]), 1);
		else if (com[i] == '[' && !buf[j])
			while (ok && ++i)
			{
				if (com[i] == '[')
					ok++;
				if (com[i] == ']')
					ok--;
			}
		else if (com[i] == ']' && buf[j])
			while (ok && --i)
			{
				if (com[i] == ']')
					ok++;
				if (com[i] == '[')
					ok--;
			}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc > 1 && str_size(argv[1]) <= LEN_SIZE)
	{
		i = -1;
		str = (char*)malloc(sizeof(char) * BUF_SIZE);
		while (++i < BUF_SIZE)
			str[i] = 0;
		ft_brainfuck(str, argv[1]);
		free(str);
	}
	else
		write(1, "\n", 1);
	//write(1, "\n", 1);
	return (0);
}
