#include <stdio.h>
#include <stdlib.h>

int		ft_nod(int num1, int num2)
{
	int		ost;

	ost = num1 % num2;
	if (ost == 0)
		return (num2);
	else
		return (ft_nod(num2, ost));
}

int		main(int argc, char **argv)
{
	int		num1;
	int		num2;
	int		nod;

	if (argc == 3 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		// Алгоритм Эвклида
		if (num1 > num2)
			nod = ft_nod(num1, num2);
		else
			nod = ft_nod(num2, num1);
		printf("%d\n", nod);
	}
	else
		printf("Error\n");
	return (0);
}
