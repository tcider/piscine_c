#include <stdio.h>

int ft_str_is_numeric(char *str)
{
	while(*str)
	{
		if (!(*str > '0' && *str < '9'))
			return (0);
		str ++;
	}
	return (1);
}

int main()
{
char string[] = "";
char *str;

str = &string[0];
printf("%d", ft_str_is_numeric(str));
}
