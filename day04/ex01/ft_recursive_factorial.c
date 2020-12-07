#include <stdio.h>
#include <time.h>

int ft_recursive_factorial(int nb)
{
	if (nb == 0) return 1;
	else if (nb < 0) return 0;
	else return nb*ft_recursive_factorial(nb-1);
}

int main()
{
	time_t start, end;
	int y;

	start = time(NULL);
	y = ft_recursive_factorial(10);
	end = time(NULL);
	printf("Result - %d . Time, sec = %f", y, difftime(end, start));
	
}

