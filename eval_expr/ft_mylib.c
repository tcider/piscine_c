# include "ft_eval_expr.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

int		ft_atoi(char *str)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (sign * num);
}

char	ft_is_num(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

char	ft_is_op(char c)
{
	if (c == '-' || c == '+' || c == '/' || c == '*' || c == '%')
		return (1);
	else
		return (0);
}
