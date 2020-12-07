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

int ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return 2;
	while (!ft_is_prime(nb))
		nb ++;
	return nb;
}

int main()
{
printf("%d", ft_find_next_prime(20));
}

