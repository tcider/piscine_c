#include <stdio.h>
int ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int n;
	int k;
	int sum;
	int j;
	int st;

	n = 0;
	while (base[n])
		n++; // Основание считемы исчисления
	i = 0;
	sign = 1;
	while (str [i] == ' ' || str[i] == '\n')
		i ++;
	if (str[i] == '-')
	{
		sign = -1;
		i ++;
	}
	k = i;
	while (str[i])
		i ++;
	i --;
	j = 0;
	while (str[i] != base[j])
		j ++;
	sum = j;
	st = 1;
	while (i > k)
	{
		i --;
		j = 0;
		while (str[i] != base[j])
			j ++;
		st = n*st;
		sum = sum + st * j;
	}
	return sum * sign;

}

int main()
{
printf("%d", ft_atoi_base("D15", "0123456789ABCDEF"));


}

