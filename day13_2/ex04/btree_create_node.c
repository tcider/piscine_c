#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*ptr;

	ptr = (t_btree*)malloc(sizeof(t_btree));
	if (ptr)
	{
		ptr->item = item;
		ptr->right = NULL;
		ptr->left = NULL;
	}
	return (ptr);
}
