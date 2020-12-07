#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	tmp2 = *begin_list;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		(*begin_list)->next = tmp1;
		tmp1 = *begin
	}



