#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int tmp;

	tmp = *a % *b;
	*a /= *b;
	*b = tmp;
}

int main()
{
int x;
int y;
int *a;
int *b;

x = 19;
y = 5;
a = &x;
b = &y;
printf("x=%d, y=%d\n",x,y);
ft_ultimate_div_mod(a, b);
printf("x, div=%d, y, mod=%d",x,y);





}

