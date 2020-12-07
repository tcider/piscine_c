#include <unistd.h>

int	if_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || !c)
		return (1);
	return (0);
}

int if_up_noend(char c, char b)
{
	if (c >= 'A' && c <= 'Z' && !if_space(b))
		return (1);
	return (0);
}

int	if_lo_last_ch(char c, char b)
{
	if (!if_space(c) && if_space(b))
		if (c >= 'a' && c <= 'z')
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
			{
				if (argv[i][j] && if_lo_last_ch(argv[i][j], argv[i][j + 1]))
					argv[i][j] = argv[i][j] + 'A' - 'a';
				else if (argv[i][j] && if_up_noend(argv[i][j], argv[i][j + 1]))
					argv[i][j] = argv[i][j] - ('A' - 'a');
				write(1, &argv[i][j], 1);
			}
			write(1, "\n", 1);
		}
	}
	return (0);
}
