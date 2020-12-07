#include <stdio.h>

char *ft_strupcase(char *str)
{
	int n;
	int i;

	n = 'a' - 'A';
	i = 0;
	while(str[i])
	{
		if ((str[i] > 'a') && (str[i] < 'z'))
//			printf("\n");
			str[i] = n;
		i ++;
	}
	return (str);
}

int main()
{
char *str = "123Hello123";

str = ft_strupcase(str);
while (*str)
	printf("%c", *str++);

}
