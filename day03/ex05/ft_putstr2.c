#include <stdio.h>

void ft_putchar(char a)
{
	printf("%c", a);
}

void ft_putstr(char *str)
{
	//int i;

	//i = 0;
	while (*str)
	{
		ft_putchar(*str++);
		//i ++;
	}

}

int main()
{
char b[] = "Hello";
char *str;

str = &b[0];
ft_putstr(str);


}

