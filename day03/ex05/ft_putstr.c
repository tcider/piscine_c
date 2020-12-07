#include <stdio.h>
void ft_putchar(char a)
{
	printf("%c", a);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str++);
		//str++;
	}

}

int main()
{
	char string[] = "Say my bitch up";
	char *str;

	str = &string[0];
	ft_putstr(str);
}

