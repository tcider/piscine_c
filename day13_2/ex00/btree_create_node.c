#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*btree;

	btree = (t_btree*)malloc(sizeof(t_btree));
	btree->item = item;
	return btree;
}
