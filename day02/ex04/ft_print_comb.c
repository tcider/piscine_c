#include <stdio.h>

void ft_putchar(char c)
{
	printf("%c",c);
}

void ft_print_comb(void)
{
	int n=0;
	char a,b,c;
	a='0'-1;
	while (++a<='9')
	{
		b=a+1;
		while (('9'-b)>=0)
		{
			c=b+1;
			while (('9'-c)>=0)
			{
				n++;
				ft_putchar(a);
			//	if (b!=a)
					ft_putchar(b);
			//	if (c!=a && c!=b)
					ft_putchar(c);
				printf(",");
				c++;
			}
			b++;
		}
	//	a++;
	}
	ft_putchar('\n');
	printf("%d",n);


}

int main()
{
ft_print_comb();
}
