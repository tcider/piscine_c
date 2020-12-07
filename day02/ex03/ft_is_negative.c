#include <stdio.h>

void ft_putchar(int c)
{
	printf("%c",c);
}

void ft_is_negative(int n)
{
	char a;
	if (n<0)
		a='N';
	else
		a='P';
	ft_putchar(a);
}

int main()
{
ft_is_negative(5);
}
