#include <stdio.h>

int ft_is_prime(int nb)
{
	int delitel;

	if (nb <= 1)
		return 0;
	delitel = 2;
	while (delitel * delitel <= nb)
	{
		if (nb % delitel == 0)
			return 0;
		delitel ++;
	}
	return 1;
}

int main()
{
printf("%d", ft_is_prime(4));
}

