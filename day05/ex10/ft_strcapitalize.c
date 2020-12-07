#include <stdio.h>
#define LOWLETTER(x) ((x >= 'a') && (x <= 'z'))
#define UPLETTER(x) ((x >= 'A') && (x <= 'Z'))

char *ft_strcapitalize(char *str)
{
	int n;
	int i;

	n = 'a' - 'A';
	i = 0;
	while(str[i])
	{
		if ((str[i] == ' ') && (LOWLETTER(str[i + 1]) || UPLETTER(str[i + 1])))
			if(LOWLETTER(str[i + 1]))
				str[i + 1] -= n;
//				printf("L");
			i ++;
	}
	return (str);
}

int main()
{
char string[] = "123 Hello 123   bv";
char *str;

str = &string[0];
str = ft_strcapitalize(str);
while (*str)
	printf("%c", *str++);

}
