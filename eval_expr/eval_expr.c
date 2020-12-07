#include "ft_eval_expr.h"

char	ft_is_sign(char *str, int i)
{

	if (str[i] != '-' && str[i] != '+')
		return (0);
	if (str[i + 1] && !ft_is_num(str[i + 1]))
		return (0);
	i--; 
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i--;
	if (i >= 0 && (ft_is_num(str[i]) || str[i] == ')'))
		return (0);
	return (1);
}

char	ft_prior_op(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return (3);
	else if (c == '+' || c == '-')
		return (2);
	else if (c == '(' || c == ')')
		return (1);
	else
		return (0);
}

t_index	ft_op_num(char *str, char *res, char *tmp, t_index ind)
{
	if (str[ind.i] == '-' && ft_is_sign(str, ind.i))
		res[ind.j++] = str[ind.i++];
	if (str[ind.i] == '+' && ft_is_sign(str, ind.i))
		ind.i++;
	if (ft_is_num(str[ind.i]))
	{
		while (str[ind.i] && ft_is_num(str[ind.i]))
			res[ind.j++] = str[ind.i++];
		res[ind.j++] = ' ';
	}
	if (ft_is_op(str[ind.i]))
	{
		while (ind.k >= 0 && ft_prior_op(tmp[ind.k]) >= ft_prior_op(str[ind.i]))
		{
			res[ind.j++] = tmp[ind.k--];
			res[ind.j++] = ' ';
		}
		tmp[++ind.k] = str[ind.i++];
	}
	return (ind);
}

t_index	ft_scoup(char *str, char *res, char *tmp, t_index ind)
{
	if (str[ind.i] == '(')
		tmp[++ind.k] = str[ind.i++];
	if (str[ind.i] == ')')
	{
		while (ind.k >= 0 && tmp[ind.k] != '(')
		{
			res[ind.j++] = tmp[ind.k--];
			res[ind.j++] = ' ';
		}
		ind.k--;
		ind.i++;
	}
	while (str[ind.i] == ' ' || str[ind.i] == '\n' || str[ind.i] == '\t')
		ind.i++;
	return (ind);
}

char	*ft_expr_rpn(char *str)
{
	char	*res;
	char	*tmp;
	t_index	index;

	index.i = 0;
	index.j = 0;
	index.k = -1;
	res = (char*)malloc(sizeof(char) * BUF_SIZE + 1);
	tmp = (char*)malloc(sizeof(char) * BUF_SIZE);
	while (str[index.i])
	{
		index = ft_op_num(str, res, tmp, index);
		index = ft_scoup(str, res, tmp, index);
	}
	while (index.k >= 0)
	{
		res[index.j++] = tmp[index.k--];
		res[index.j++] = ' ';
	}
	res[index.j] = '\0';
	free(tmp);
	return (res);
}
