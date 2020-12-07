#include <stdio.h>
void ft_putchar(char a)
{
	printf("%c", a);
}

char ft_strrev(char *str)
{
	char temp;
	int i;
	int j;
	
	i = 0;
	while (str[i])
		i ++;
	i --;
	j = 0;
	while (j < i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j ++;
		i --;
	}

//	str_temp = &str[0];
//	str = &str[0];
//	while(*str)
//	{
//		*str_temp++ = *str++;
//
//	}
	return (*str);


}

int main()
{
	char string[] = "Hello";
	char *str;
	char *str2;
	
	str = &string[0];
	str2 = &string[0];
	while (*str2)
		printf("%c", *str2++);
	printf("\n");
	ft_strrev(str);
	while (*str)
		printf("%c", *str++);
	//printf("%d",ft_strrev(str));

}

