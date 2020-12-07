#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;
	
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->data = NULL;
		(*begin_list)->next = NULL;
		free(*begin_list);
		*begin_list = tmp;
	}
}
