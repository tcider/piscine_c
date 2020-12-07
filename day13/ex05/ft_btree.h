#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h> // кажется он не нужен так же как и креате_ноде

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree *btree_create_node(void *item);

#endif
