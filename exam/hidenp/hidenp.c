#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	j = 0;
	while (argv[2][i])
	{
		while (argv[1][j] == argv[2][i])
		{
			i++;
			j++;
		}
		i++;
	}
	if (!argv[1][j])
	{
		write(1, "1\n", 2);
		return 1;
	}
	write(1, "0\n", 2);
	return 0;
}
