#include "ft_list.h"
#include <stdio.h>

int	main()
{
	t_list	*list;
	char	str[] = "Hello";

	list = ft_create_elem(str);
	printf("%s", (char*)list->data);
}

