#include "ft_list.h"
#include <stdio.h>

int	main()
{
	t_list	*list;
	//t_list	*list2;
	
	char	str[] = "Hello";
	char	str2[] = "Hello2";
	//char	str3[] = "Hello3";
	//list2 = NULL;
	list = ft_create_elem(str);
	ft_list_push_back(&list, str2);
	//ft_list_push_front(&list, str3);
	//list2 = list;
	printf("%d\n", ft_list_size(list));
	while (list)
	{
		printf("%s", (char*)list->data);
		list = list->next;
	}
}

