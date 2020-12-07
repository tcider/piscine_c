#include <stdio.h>

void ft_putchar(char x)
{
	printf ("%c", x);
}

void ft_print_comb2(void)
{
	int n;
	int i;

	n = 0;
	while (n < 100)
	{
		i = n + 1;
		while (i < 100)
		{
			ft_putchar(n / 10 + '0');
			ft_putchar(n % 10 + '0');
			ft_putchar(' ');
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			if (n != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			i++;
		}
		n++;
	}

}

int main()
{
	ft_print_comb2();
}



