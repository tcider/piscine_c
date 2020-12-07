#include "ft_list.h"



t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		i;
	t_list	*tmp2;
	t_list	*tmp3;
	t_list	*tmp4;

	tmp2 = lst;
	i = 0;
	while (tmp2->next)
	{
		i++;
		tmp2 = tmp2->next;
	}
	while(--i)
	{
		tmp2 = lst;
		tmp3 = 0;
		while (tmp2->next)
		{
			if (!cmp(tmp2->data, (tmp2->next)->data))
			{
				tmp4 = tmp2->next;
				tmp2->next = tmp4->next;
				tmp4->next = tmp2;
				if (tmp3)
					tmp3->next = tmp4;
				else
					lst = tmp4;
				tmp3 = tmp4;
			}
			else
			{
				tmp3 = tmp2;
				tmp2 = tmp2->next;
			}
		}
	}
	return (lst);
}

int		ascending(int a, int b)
{
	return (a <= b);
}

int		main(void)
{
	t_list	*list_new;
	t_list	*list;
	int		str[] = {5, 0, 3, 3, 1, 4, 9, 2, 1};
	int	i;

	i = 0;
	list = NULL;
	while (i < 9)
	{
		list_new = (t_list*)malloc(sizeof(t_list));
		list_new->data = str[i];
		list_new->next = list;
		list = list_new;
		i++;
	}
	
	while (list)
	{
		printf("%d-", list->data);
		list = list->next;
	}
	
	list = sort_list(list_new, ascending);
	
	printf("\n");
	while (list)
	{
		printf("%d-", list->data);
		list = list->next;
	}
	printf("\n");
	
	return (0);
}
