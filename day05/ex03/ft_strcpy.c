#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return dest;
}


int main()
{
char *string = "Hello";
char *string2 = "Abcde";
char **string3;

while (*string)
	printf("%c", *string++);
printf("\n");
printf("\n");
printf("\n");
string3 = ft_strcpy(string2, string);
while (**string3)
	printf("%c", **string3++);
}
