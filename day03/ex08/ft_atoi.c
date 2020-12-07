#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r')
		i ++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return num * sign;

}


int main()
{
int a;
char string[] = "	         	-3343 33\n";
char *str;

str = &string[0];
a = ft_atoi(str);
printf("%d", a);
//printf('\n');
//printf("%d", atoi(str));



}

