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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
// удалить прототип указателя на ф-ю здесь и дот этого
int		ft_str_cmp(char *str1, char *str2);
// проверить здесь и впред заданиях если входящий t_list NULL
#endif
