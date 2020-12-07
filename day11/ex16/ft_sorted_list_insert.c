#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_list;
	t_list	*tmp_list;
	t_list	*prev_list;

	new_list = ft_create_elem(data);
	prev_list = NULL;
	tmp_list = *begin_list;
	while (tmp_list && !new_list->next)
	{
		if (cmp(tmp_list->data, data) > 0)
		{
			if (prev_list)
				prev_list->next = new_list;
			else
				*begin_list = new_list;
			new_list->next = tmp_list;
		}
		prev_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	if (!new_list->next)
		prev_list->next = new_list;
}

