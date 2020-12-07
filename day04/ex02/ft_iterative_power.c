#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
	int i;
	int itog;

	if (power < 0)
		return 0;
	if (power == 0)
		return 1;
	i = 1;
	itog = 1;
	while (i ++ <= power)
		itog *= nb;
	return itog;
}

int main()
{
int x = 3;
int y = 1;
int z;

z = ft_iterative_power(x, y);
printf("%d", z);
}
