#include <stdio.h>

char *ft_strdup(char *src)
{
	char *str2;
	int i;
	
	i = 0;
	while(src[i])
		i ++;
	if (!(str2 = (char *)malloc(sizeof (char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		str2[i] = src[i];
		i ++;
	}
	str2[i] = '\0';
	return (str2);

}

int main()
{
	fvdv




}
