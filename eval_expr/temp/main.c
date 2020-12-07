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


/* Заменить на этот мейн
int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar(’\n’);
	}
	return (0);
}
Поменять потом майн на этот
*/

int			main(void)
{
	char str1[] = "-3 + 4";
	char str2[] = "((+1 * 2) * 3) - 4";
	char str3[] = "50 * (7 - (10 / 2))";
	char str4[] = "-42";
	char str5[] = "+42";
	char str6[] = "1 + 1";
	char str7[] = "10 * 0";
	char str8[] = "10 * 10";
	char str9[] = "10 / 10";
	char str10[] = "10 % 3";
	char str11[] = "10*5 * 1*1*6 * 4*98 *40*4";
	char str12[] = "1 + 1 - 42 / 435 * 23 + 34 - 12 * 12";
	char str13[] = "((1 + 1 - 42) / 435 * ((23 + 34) - 12) * 12)";
	char str14[] = "(((1 + 1 - 42) / (435 * ((23 + 34) - 12) * 1) + 2))";
	char str15[] = "((10*5*1*1*6*4*98* 40*4+1 +2/4+97*87+657+78/584*34))";
	char str16[] = "((((1 + ((((1 - 42))))) / (435 * ((23 + 34) - 12) * 1) + 2)))";
	char str17[] = "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1";
	
	printf("%s\n%s\n%d\n\n", str1, ft_expr_rpn(str1), eval_expr(str1));
	printf("%s\n%s\n%d\n\n", str2, ft_expr_rpn(str2), eval_expr(str2));
	printf("%s\n%s\n%d\n\n", str3, ft_expr_rpn(str3), eval_expr(str3));
	printf("%s\n%s\n%d\n\n", str4, ft_expr_rpn(str4), eval_expr(str4));
	printf("%s\n%s\n%d\n\n", str5, ft_expr_rpn(str5), eval_expr(str5));
	printf("%s\n%s\n%d\n\n", str6, ft_expr_rpn(str6), eval_expr(str6));
	printf("%s\n%s\n%d\n\n", str7, ft_expr_rpn(str7), eval_expr(str7));
	printf("%s\n%s\n%d\n\n", str8, ft_expr_rpn(str8), eval_expr(str8));
	printf("%s\n%s\n%d\n\n", str9, ft_expr_rpn(str9), eval_expr(str9));
	printf("%s\n%s\n%d\n\n", str10, ft_expr_rpn(str10), eval_expr(str10));
	printf("%s\n%s\n%d\n\n", str11, ft_expr_rpn(str11), eval_expr(str11));
	printf("%s\n%s\n%d\n\n", str12, ft_expr_rpn(str12), eval_expr(str12));
	printf("%s\n%s\n%d\n\n", str13, ft_expr_rpn(str13), eval_expr(str13));
	printf("%s\n%s\n%d\n\n", str14, ft_expr_rpn(str14), eval_expr(str14));
	printf("%s\n%s\n%d\n\n", str15, ft_expr_rpn(str15), eval_expr(str15));
	printf("%s\n%s\n%d\n\n", str16, ft_expr_rpn(str16), eval_expr(str16));
	printf("%s\n%s\n%d\n\n", str17, ft_expr_rpn(str17), eval_expr(str17));


	return (0);
}
