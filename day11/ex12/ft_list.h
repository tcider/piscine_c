#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
// for test
# include <stdio.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()); 
// fot test
int		ft_str_cmp(char *str1, char *str2);

#endif
