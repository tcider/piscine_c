#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev_list;
	t_list	*curent_list;

	curent_list = *begin_list;
	prev_list = NULL;
	while (curent_list)
	{
		if (!cmp(curent_list->data, data_ref))
		{
			if (prev_list)
				prev_list->next = curent_list->next;
			else
				*begin_list = curent_list->next;
			free(curent_list);
			curent_list = prev_list;
		}
		prev_list = curent_list;
		if (prev_list)
			curent_list = curent_list->next;
		else
			curent_list = *begin_list;
	}
}
