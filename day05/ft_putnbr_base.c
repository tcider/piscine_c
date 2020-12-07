#include <stdio.h>

void ft_putnbr_base(int nbr, char *base)
{
	int n;
	int k;
	char ost[10];

	//ost = NULL;
	n = 0;
	k = 0;
	while (base[n])
		n ++;
	while (nbr != 0)
	{
		//printf("%c", base[0]);
		//printf("/n");
		ost[k] = base[nbr % n];
		
		//printf("%c", ost[k]);
		nbr /= n;
		k ++;
	}
	while (k!=0)
	{
		k --;
		printf("%c", ost[k]);
	}
	
}

int main()
{
char string[]="0123456789ABCDEF";
char *str;

str = &string[0];

ft_putnbr_base(3349, str);
}

