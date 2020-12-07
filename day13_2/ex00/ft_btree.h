#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct s_btree	t_btree;

struct	s_btree
{
	void		*item;
	t_btree		*left;
	t_btree		*right;
};

#endif
