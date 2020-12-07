#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h> // for test
# include <stdio.h> // for test

typedef struct		s_list
{
	struct s_list	*next;
	int				data;
}					t_list;

#endif
