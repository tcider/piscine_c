#include "ft_list.h"

void	ft_elem_insert(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*tmp_list;
	t_list	*prev_list;
	int		flag;
	
	flag = 0;
	prev_list = NULL;
	tmp_list = *begin_list;
	while (tmp_list && !flag)
	{
		if (cmp(tmp_list->data, elem->data) > 0)
		{
			if (prev_list)
				prev_list->next = elem;
			else
				*begin_list = elem;
			elem->next = tmp_list;
			flag = 1;
		}
		prev_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	if (!flag)
		prev_list->next = elem;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*tmp_list;

	while (begin_list2)
	{
		tmp_list = begin_list2->next;
		ft_elem_insert(begin_list1, begin_list2, cmp);
		begin_list2 = tmp_list;
	}
}
