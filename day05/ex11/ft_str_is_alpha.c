#include <stdio.h>
#define LOWLETTER(x) ((x >= 'a') && (x <= 'z'))
#define UPLETTER(x) ((x >= 'A') && (x <= 'Z'))

int ft_str_is_alpha(char *str)
{
	while(*str)
	{
		if (!(LOWLETTER(*str) || UPLETTER(*str)))
			return (0);
		str ++;
	}
	return (1);
}

int main()
{
char string[] = "Hellobv";
char *str;

str = &string[0];
printf("%d", ft_str_is_alpha(str));
}
