#ifndef FT_LIST_H
# define FT_LIST_H

// for test
# include <stdio.h>
// for test
# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);  

#endif
