#include <stdio.h>

void ft_putchar(char a)
{
	printf("%c", a);
}

void ft_putnbr(int nb)
{
	int i;
	char *x;

	i = 0;
	while (nb > 1)
	{
		*x++ = '0' + nb % 10;
		nb /= 10;
		i ++;
	}
	while (i >= 0)
	{
		ft_putchar(*x--);
		i --;

	}
//	printf("%d", i);
//	while (i >= 1)
//	{
//		nb = nb / i;
//		ft_putchar('0' + nb);
//		i /= 10;
//
//	}

}

int main()
{
	int x=2890;

	ft_putnbr(x);
}


