#include <unistd.h>

unsigned int	two_power(int power)
{
	int	num;

	num = 1;
	return (num << power);
}

void print_bit(int num)
{
	unsigned int		n;

	n = two_power(31);
	while (n)
	{
		if ((num & n) == n)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (n == two_power(24) || n == two_power(16) || n == two_power(8))
			write(1, " ", 1);
		n /= 2;
	}
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	unsigned int		num;
	int		flag;

	i = 0;
	num = 0;
	flag = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (argv[i][++j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z' && argv[i][j] != 'h')
					num |= two_power(argv[i][j] - 'a');
				else
					flag = 1;
			}
		}
	}
	if (!flag)
		print_bit(num);
}
