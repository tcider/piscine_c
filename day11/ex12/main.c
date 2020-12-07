#include "ft_list.h"

int			main(void)
{
	t_list	**begin_list;
	t_list  *list_new;
    t_list  *list;
    char    *str[] = {"str1", "str2", "str3", "str4"};
    int     i;

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
	begin_list = &list;
    ft_list_remove_if(begin_list, "str2", ft_str_cmp);
    while (*begin_list)
    {
         printf("%s\n", (*begin_list)->data);
         (*begin_list) = (*begin_list)->next;
    }
}
