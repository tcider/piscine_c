#include "ft_list.h"

int			main(void)
{
	t_list	**begin_list;
	t_list	*begin_list2;
	t_list  *list_new;
    t_list  *list;
    char    *str[] = {"str6", "str4", "str2", "str1"};
	char    *str2[] = {"str7", "str5", "str3", "str2", "str0"};

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
	i = 0;
    begin_list2 = NULL;
	list_new = NULL;
    while (i <= 4)
    {
        list_new = (t_list*)malloc(sizeof(t_list));
		list_new->data = str2[i];
        list_new->next = begin_list2;
        begin_list2 = list_new;
        i++;
    }
    ft_sorted_list_merge(begin_list, begin_list2, ft_str_cmp);
    while (*begin_list)
    {
         printf("%s\n", (*begin_list)->data);
         (*begin_list) = (*begin_list)->next;
    }
}
