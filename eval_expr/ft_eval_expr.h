#ifndef FT_EVAL_EXPR_H
# define FT_EVAL_EXPR_H

# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 2048

typedef struct	s_index
{
	int		i;
	int		j;
	int		k;
}				t_index;

int		eval_expr(char *);
void	ft_putnbr(int);
void	ft_putchar(char);
int		ft_atoi(char *);
char	ft_is_num(char);
char	ft_is_op(char);
char	*ft_expr_rpn(char *);

#endif
