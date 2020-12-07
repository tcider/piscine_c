#include "ft_eval_expr.h"

int			ft_round(double num)
{
	if (num < 0)
		num -= 0.5;
	else
		num += 0.5;
	return ((int)num);
}

double		operation(double val1, double val2, char op)
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
		return(ft_round(val1) % ft_round(val2));
	else
		return 0;
}

int			eval_expr(char *str)
{
	int		i;
	int		j;
	double	stack[BUF_SIZE];
	char	*rpn;

	rpn = ft_expr_rpn(str);
	i = -1;
	j = -1;
	if (ft_is_num(rpn[0]))
	{
		stack[++j] = (double)ft_atoi(rpn);
		i++;
	}
	while (rpn[++i])
	{
		if (ft_is_num(rpn[i]) && (rpn[i - 1] == ' ' || rpn[i - 1] == '-'))
			stack[++j] = (double)ft_atoi(&rpn[i - 1]);
		if (ft_is_op(rpn[i]) && !ft_is_num(rpn[i + 1]))
		{
			stack[j - 1] = operation(stack[j - 1], stack[j], rpn[i]);
			j--;
		}
	}
	free(rpn);
	return (ft_round(stack[j]));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
