#include "ft_list.h"

//Include av[0] or not? Task is like day07.03, I'v got OK on it, as i remember i didn't use av[0] there

t_list	*ft_list_push_params(int ac, char **av)
{
	int	i;
	t_list	*list;
	t_list	*list_new;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		list_new = ft_create_elem(av[i]);
		list_new->next = list;
		list = list_new;
		i++;
	}
	return(list);
}
