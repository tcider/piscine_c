#include <unistd.h>

typedef struct	s_result
{
	int	i;
	int rad;
}				t_result;

int	radius(char *str, int i)
{
	int		rad;

	rad = 0;
	while (i - rad >= 0 && str[i + rad] && str[i - rad] == str[i + rad])
		rad++;
	return (rad - 1);
}

int	main(int argc, char **argv)
{
	t_result	res;
	int			i;

	i = 0;
	res.i = 0;
	res.rad = 0;
	if (argc == 2)
	{
		while (argv[1][++i])
		{
			if (radius(argv[1], i) >= res.rad)
			{
				res.rad = radius(argv[1], i);
				res.i = i;
			}
		}
	}
	if (res.rad)
	{
		i = res.i - res.rad - 1;
		while (++i <= res.i + res.rad)
			write(1, &argv[1][i], 1); 
	}
	write(1, "\n", 1);
}
