#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev_list;
	t_list	*next_list;
	t_list	*list;

	prev_list = NULL;
	list = *begin_list;
	while(list)
	{
		if (!cmp(list->data, data_ref))
		{
			if (prev_list)
				prev_list->next = list->next;
			else
				*begin_list = list->next;
			next_list = list->next;
			list->data = NULL;
			list->next = NULL;
			free(list); 
			list = next_list;
		}
		else
		{
			prev_list = list;
			list = list->next;
		}
	}
}
