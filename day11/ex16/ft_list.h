#ifndef FT_LIST_H
# define FT_LIST_H

// for test
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void		ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
int			ft_str_cmp(char *str1, char *str2);
t_list		*ft_create_elem(void *data);

#endif
