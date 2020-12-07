#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp_list;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	tmp_list = *begin_list1;
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	tmp_list->next = begin_list2;
}
