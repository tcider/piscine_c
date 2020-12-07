#include "ft_list.h"

int		ft_list_size(t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp_list;
	int		i;
	int		j;
	int		size;
	void	*tmp;

	size = ft_list_size(begin_list);
	i = 0;
	while (begin_list && ++i <= size / 2)
	{
		j = 0;
		tmp_list = begin_list;
		while (tmp_list)
		{
			if (++j == size - (i - 1) * 2)
			{
				tmp = begin_list->data;
				begin_list->data = tmp_list->data;
				tmp_list->data = tmp;
			}
			tmp_list = tmp_list->next;
		}
		begin_list = begin_list->next;
	}
}
