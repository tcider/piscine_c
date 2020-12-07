#include "ft_list.h"

//Головной элемент списка считатуь нулевым или первым? у меня нулевой

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int    i;
	
	i = 0;
	while (i < nbr)
	{
		if (!begin_list->next)
			return (NULL);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
