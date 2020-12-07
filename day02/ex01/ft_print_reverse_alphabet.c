#include <stdio.h>

void ft_print_reverse_alphabet(void)
{
	int x='a', y='z';
	while (y>=x)
		printf("%c",y--);
}

int main()
{
	ft_print_reverse_alphabet();
}

