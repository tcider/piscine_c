#include "rpn_calc.h"

char		over_atoi(char *str)
{
	int		check_sum;
	int		num;
	int		i;

	num = atoi(str);
	check_sum = 0;
	i = -1;
	while (str[++i] && !check_sum)
		if (str[i] >= '0' && str[i] <= '9')
			while (str[i] >= '0' && str[i] <= '9')
			{
				check_sum += str[i] - '0';
				i++;
			}
	if (num < 0)
		num = -num;
	while (num)
	{
		check_sum -= num % 10;
		num = num / 10;
	}
	if (check_sum)
		return (1);
	return (0);
}

int		operation(int val1, int val2, char op)
{
	if (op == '+')
		return(val1 + val2);
	else if (op == '-')
		return(val1 - val2);
	else if (op == '*')
		return(val1 * val2);
	else if (op == '/')
		return(val1 / val2);
	else if (op == '%')
		return(val1 % val2);
	else
		return 0;
}

int		if_op(char c, char b)
{
	if (c == '-' && ((b && b == ' ') || !b))
		return 1;
	if (c == '*' || c == '/' || c== '+' || c == '%')
		return 1;
	return 0;
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		stack[BUF];

	if (argc == 2)
	{
		i = -1;
		j = -1;
		if (argv[1][0] > '0' && argv[1][0] < '9')
		{
			stack[++j] = atoi(argv[1]);
			i++;
		}
		while (argv[1][++i])
		{
			if (argv[1][i] > '0' && argv[1][i] < '9' &&
						(argv[1][i - 1] == ' ' || argv[1][i - 1] == '-'))
				stack[++j] = atoi(&argv[1][i - 1]);
			if (if_op(argv[1][i], argv[1][i + 1]))
			{
				if (j < 1 || (argv[1][i] == '/' && stack[j] == 0))
				{
					printf("Error\n");
					return 1;
				}
				stack[j - 1] = operation(stack[j - 1], stack[j], argv[1][i]);
				j--;
			}
		}
		if (j == 0)
		{
			printf("%d\n", stack[j]);
			return 0;
		}
	}
	printf("Error\n");
	return 1;
}
