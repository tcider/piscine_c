#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

int	main(void)
{
	t_list	*list_new;
	t_list	*list;
	char	*str[] = {"str1", "str2", "str3", "str4"};
	int	i;

	i = 0;
	list = NULL;
	while (i <= 3)
	{
		list_new = (t_list*)malloc(sizeof(t_list));
		list_new->data = str[i];
		list_new->next = list;
		list = list_new;
		//free(list_new);
		i++;
	}
	//while (list)
	//{
	//	printf("%s\n", list->data);
	//	list = list->next;
	//}

	list_new = ft_list_last(list);
	printf("%s", list_new->data);
}
