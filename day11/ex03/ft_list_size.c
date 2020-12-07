#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;
	t_list	*tmp;
	
	tmp = begin_list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

