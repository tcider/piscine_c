#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*num_hex(unsigned int num)
{
	char	*base;
	char	*str;
	int		tmp;
	int		i;

	base = "0123456789abcdef";
	tmp = num;
	i = 0;
	while (num)
	{
		num = num / 16;
		i++;
	}
	str = (char*)malloc((sizeof(char) + 1) * i);
	str[i] = '\0';
	num = tmp;
	while (num)
	{
		i--;
		str[i] = base[num % 16];
		num /= 16;
	}
	return str;
}

int		str_num(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return num;
}

int		main(int argc, char **argv)
{
	int		num;
	char	*str;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	num = str_num(argv[1]);
	if (num == -1)
	{
		write(1, "\n", 1);
		return 0;
	}
	str = num_hex(num);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	return 0;
}
