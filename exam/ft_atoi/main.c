#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;
	
	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{

		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

int		main(void)
{
	char	*str;
	int		num1;
	int		num2;

	str = "";
	num1 = ft_atoi(str);
	num2 = atoi(str);
	printf("%d\n%d\n", num1, num2);



}
