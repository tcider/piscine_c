#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i ++;
	while (src[j])
	{
		dest[i] = src[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
char string1[10] = "Hello";
char string2[] = "Oleg";
//char string3[] = "hellooleg";
char *str3;
int k = 0;

//str1 = &string1[0];
//str2 = &string2[0];
//str3 = &string3[0];
str3 = ft_strcat(string1, string2);
//printf("%c",*str2);
//printf("%c",*str3);
while(str3[k])
{
	printf("%c", str3[k]);
	k ++;
}
}
