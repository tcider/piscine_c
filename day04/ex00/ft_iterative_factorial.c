#include <stdio.h>
#include <time.h>

long int ft_iterative_factorial(int nb)
{
	int i;
	int x;
	
	i = 1;
	x = 1;
	while (i <= nb)
	{
		x *= i;
		i ++;
	}
	return x;
}

int main()
{
	time_t start, end;
	long int y;

	start = time(NULL);
	y = ft_iterative_factorial(10);
	end = time(NULL);
	printf("Result - %ld . Time, sec = %f", y, difftime(end, start));
	
}

