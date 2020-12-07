#include <stdio.h>

int ft_sqrt(int nb)
{
	int result;

	if (nb <= 0)
		return 0;
	else if (nb == 1)
		return 1;
	result = 2;
	while (result <= nb / 2)
	{
		if (result * result == nb)
			return result;
		result ++;
	}
	return 0;
}

int main()
{
printf("%d", ft_sqrt(4));
}
