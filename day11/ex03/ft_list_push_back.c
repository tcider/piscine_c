#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (!(*begin_list))
	{
		*begin_list = new;
		return ;
	}
	while ((*begin_list)->next)
		*begin_list = (*begin_list)->next;
	(*begin_list)->next = new;
}

