#ifndef FT_LIST_H
# define FT_LIST_H

// for test
# include <stdio.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
// need only for test
//void	ft_f(void *data);
//int		ft_cmp(void *data, void *ref);

#endif
