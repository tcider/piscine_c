#include "ft_list.h"

void	func(void **data)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 5);
	str = "abcd";
	*data = str;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void **))
{
	while (begin_list)
	{
		f(&(begin_list->data));
		begin_list = begin_list->next;
	}
}

int		main(void)
{
	t_list	*list;
	t_list	*list_next;
	int		i;
	char	*str[5] = {"a1", "a2", "abc3", "ab4", "a5"};
	void	(*ff)(void **);

	i = -1;
	list_next = NULL;
	ff = func;
	while (++i < 5)
	{
		list = (t_list*)malloc(sizeof(t_list));
		list->data = str[i];
		list->next = list_next;
		list_next = list;
	}
	/*
	while(list_next)
	{
		printf("%s\n", list_next->data);
		list_next = list_next->next;
	}
	*/
	ft_list_foreach(list_next, ff);

	while(list_next)
	{
		printf("%s\n", list_next->data);
		list_next = list_next->next;
	}

	return (0);
}
