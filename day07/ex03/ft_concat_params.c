#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char *ft_strcat(char *dst, char *src)
{
	int i;
	int j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}	
	dst[i] = '\0';
	return (dst);
}


char *ft_concat_params(int argc, char **argv)
{
	char *result;
	int i;
	int len;

	i = - 1;
	len = 0;
	while (++ i < argc)
	{
		len +=ft_strlen(argv[i]); 
		i ++;
	}
	result = (char*)malloc(sizeof(char) * (len));
	i = -1;
	while (++ i < argc)
	{
		result = ft_strcat(result, argv[i]);

//		i ++;
	}	
	return (result);
}


//int main()

int main(int argc, char *argv[])
{
//	char string[] = "Hello";
//	char string2[] = "Oleg";
//	char *str2;
	char *str;
	int i;
//	printf("%s", ft_concat_params(argc, argv));
//	printf("%d\n", argc);
//	str = &string[0];
//	str2 = &string2[0];
	str = ft_concat_params(argc, argv);
	i = 0;
	while (str[i])
	{
		printf("%c",str[i]);
		i ++;
	}
}
