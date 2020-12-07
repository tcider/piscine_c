#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_create_elem(data);
	if (!(*begin_list))
	{
		*begin_list = new;
		return ;
	}
	tmp = *begin_list;
	while ((*begin_list)->next)
		*begin_list = (*begin_list)->next;
	(*begin_list)->next = new;
	*begin_list = tmp;
}

