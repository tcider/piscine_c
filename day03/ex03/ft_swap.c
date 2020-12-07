#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

int main()
{
int x;
int y;
int *a;
int *b;

x = 1;
y = 10;
a = &x;
b = &y;
printf("x=%d, y=%d\n",x,y);
ft_swap(a, b);
printf("x=%d, y=%d",x,y);





}

