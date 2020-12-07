#include "ft_list.h"

int	main(void)
{
	t_list	**begin_list1;
	t_list	*list2;
	t_list  *list_new;
	t_list	*list_new2;
    t_list  *list;
    char    *str[] = {"str1", "str2", "str3", "str4"};
	char	*str2[] = {"ptr1", "ptr2", "ptr3"};
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
		begin_list1 = &list;
        i = 0;
        list2 = NULL;
        while (i <= 2)
        {
                list_new2 = (t_list*)malloc(sizeof(t_list));
                list_new2->data = str2[i];
                list_new2->next = list2;
                list2 = list_new2;
                i++;
        }
		ft_list_merge(begin_list1, list2);
        while (*begin_list1)
        {
              printf("%s\n", (*begin_list1)->data);
              (*begin_list1) = (*begin_list1)->next;
        }
}
