#include "ft_list.h"

void	func(void **p)
{
	char	*tmp;
	void	*tmp2;
	///char	*tmp2;
	//int		i;

	tmp = (char*)malloc(2);
	//tmp2 = p;
	//i = 0;
	//while (tmp2[i])
	//{
	//	tmp[i] = tmp2[i];
	//	i++;
	//}
	//tmp[i] = '\n';
	tmp[0] = 'a';
	tmp[1] = '\n';
	tmp2 = tmp;
	//p = NULL;
	p = &(tmp2);
}

int	main(void)
{
	t_list	*list_new;
	t_list	*list;
	char	*str[] = {"str1", "str2", "str3", "str4"};
	int	i;
	void	(*ff)(void **);

	ff = func;
	i = 0;
	list = NULL;
	while (i <= 3)
	{
		list_new = (t_list*)malloc(sizeof(t_list));
		list_new->data = str[i];
		list_new->next = list;
		list = list_new;
		i++;
	}
	ft_list_foreach(list, ff);
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}

}

