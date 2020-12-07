#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char	if_prime(int num)
{
	int		i;

	i = 3;
	if (num == 2)
		return (0);
	if (num % 2 == 0)
		return (1);
	while (i <= num / 2)
	{
		if (num % i == 0)
			return (1);
		i += 2;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		num;
	int		i;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	num = atoi(argv[1]);
	i = 2;
	while (if_prime(num)) 
	{
		if (!if_prime(i))
		{
			while (num % i == 0)
			{
				printf("%d*", i);
				num /= i;
			}
		}
		if (i == 2)
			i--;
		i += 2;
	}
	printf("%d\n", num);
	return (0);
}
// для сокращения кода можно убрать +=2 и делать ++
