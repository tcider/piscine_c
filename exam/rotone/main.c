#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			c = argv[1][i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (c == 'z')
					argv[1][i] = 'a';
				else if (c == 'Z')
					argv[1][i] = 'A';
				else
					argv[1][i] = c + 1;
			}
			i++;
		}
		i = -1;
		while (argv[1][++i])
			write(1, &argv[1][i], 1);
		write(1, "\n", 1);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
