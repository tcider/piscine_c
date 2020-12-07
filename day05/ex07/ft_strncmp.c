#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1) && (n > 0))
	{
		if(*s1 != *s2)
			return *s1 - *s2;
		s1 ++;
		s2 ++;
		n --;
	}
	return 0;
}

int main()
{
	char *str1 = "helbonn";
	char *str2 = "helaonnn";
	printf("%d", ft_strncmp(str1, str2, 5));
	printf("\n");
	printf("%d", 'b');
	printf("\n");
	printf("%d", 'a');

}
