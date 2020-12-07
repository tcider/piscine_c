#ifndef FT_ADVANCED_DO_OP_H
# define FT_ADVANCED_DO_OP_H

typedef int (*t_func)(int, int);

typedef struct	s_opp
{
	char	*op;
	t_func	func;
}				t_opp;

int		ft_sub(int x, int y);
int		ft_add(int x, int y);
int		ft_mul(int x, int y);
int		ft_div(int x, int y);
int		ft_mod(int x, int y);
int		ft_usage(int x, int y);

#endif
