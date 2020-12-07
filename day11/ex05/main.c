#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	
	list = ft_list_push_params(argc, argv);
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}
