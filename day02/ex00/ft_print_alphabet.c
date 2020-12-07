#include <stdio.h>

void ft_print_alphabet(void)
{
	int x='a', y='z';
	while (x<=y)
		printf("%c",x++);
}

int main()
{
	ft_print_alphabet();
}

