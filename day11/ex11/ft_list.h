#ifndef FT_LIST_H
# define FT_LIST_H

// for test
# include <stdio.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

#endif
