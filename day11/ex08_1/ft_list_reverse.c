#include "ft_list.h"
void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	while (*begin_list)
	{
		tmp2 = (*begin_list)->next;
		(*begin_list)->next = tmp1;
		tmp1 = *begin_list;
		*begin_list = tmp2;
	}
	*begin_list = tmp1;
}
