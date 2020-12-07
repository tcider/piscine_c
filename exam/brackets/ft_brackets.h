#ifndef FT_BRACKETS_H
# define FT_BRACKETS_H

# include <unistd.h>

# define BUF 1024

# define OB(x) (x == '(' || x == '[' || x == '{')
# define CB(x) (x == ')' || x == ']' || x == '}')

int		ft_check(char *str);

#endif
