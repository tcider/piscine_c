#include <stdio.h>

unsigned int	hcf(unsigned int a, unsigned int b)
{
	if (a % b == 0)
		return b;
	return hcf(b, a % b);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return 0;
	return a * b / hcf(a, b);
}

int	main()
{
	printf("%d\n", hcf(77, 14));
	return 0;
}
