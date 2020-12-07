#include "ft_list.h"

/*Птыался на практике сделать функцию меняющую значение - не получилось? делал и через указатель на указатель - не хочет и все менять? здесь поэтому так? над убрать ** и раскоментить */

void	ft_list_foreach(t_list *begin_list, void (*f)(void **))
{
	void	**tmp = NULL;

	while (begin_list)
	{
		tmp = &(begin_list->data);
		f(tmp);
		//f(begin_list->data);
		begin_list = begin_list->next;
	}
}
