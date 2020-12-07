#include <stdio.h>

int ft_strcmp2(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i]) 
			return s1[i] - s2[i];
		i ++;
	}
	return 0;
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if(*s1 != *s2)
			return *s1 - *s2;
		s1 ++;
		s2 ++;
	}
	return 0;
}

int main()
{
	char *str1 = "hellonn";
	char *str2 = "hellonnn";
	printf("%d", ft_strcmp(str1, str2));
	printf("\n");
	printf("%d", 'k');
	printf("\n");
	printf("%d", 'n');

}
