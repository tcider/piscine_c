#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp1_list;
	t_list	*tmp2_list;
	void	*tmp_data;


	tmp1_list = *begin_list;
	while (tmp1_list->next)
	{
		tmp2_list = *begin_list;
		while (tmp2_list->next)
		{
			if (cmp(tmp2_list->data, (tmp2_list->next)->data) > 0)
			{
				tmp_data = tmp2_list->data;
				tmp2_list->data = (tmp2_list->next)->data;
				(tmp2_list->next)->data = tmp_data;
			}
			tmp2_list = tmp2_list->next;
		}
		tmp1_list = tmp1_list->next;
	}

}
