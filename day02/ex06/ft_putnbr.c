#include <stdio.h>

void ft_putchar(char x)
{
	printf ("%c", x);
}

void ft_putnbr(int nb)
{
	int k;
	int a;
	
	k = 10000;
	while (k > 0)
	{
		a = nb / k;
		if (a > 0)
		{
			ft_putchar(a + '0');
			nb = nb % k;
		}
		k = k / 10;
	}

}

int main()
{
	ft_putnbr(20154);
}



