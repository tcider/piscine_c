#include <stdio.h>

void ft_putchar(char x)
{
	printf ("%c", x);
}

void ft_print_combn(int n)
{
	int i;
	int nabor[n];

	i = 0;
	while (i < n)
	{
		nabor[i] = i;
		i ++;
	}

	while (nabor[0] < (10-n))
	{
		while (nabor[n - 1] <= 9)
		{
			i = 0;
			while (i < n)
			{
				ft_putchar(nabor[i] + '0');
				i ++;
			}
			ft_putchar(',');
			nabor[n - 1] ++;
		}
		nabor[n - 1] --;
		i = 1;
		while (i < n)
		{
			if (nabor[n - i] == (10 - i))
			{
				nabor[n - i - 1] ++;
				nabor[n - i] = nabor[n - i - 1] + 1;
			}
			i ++;
		}
		nabor[n - 1] = nabor[n - 2] + 1;
		
	}

}

int main()
{
	ft_print_combn(4);
}



