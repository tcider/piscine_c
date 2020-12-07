#include <stdio.h>
void ft_putchar(char a)
{
	printf("%c", a);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		str ++;
		i ++;
	}
	return i;
}

int main()
{
	char string[] = "Hello";
	char *str;

	str = &string[0];
	printf("%d", ft_strlen(str));
}

