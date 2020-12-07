#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>
# include <stdio.h> // for test

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_list
{
	t_btree			*node;
	int				level;
	struct s_list	*next;
}					t_list;

typedef struct		s_enque
{
	t_list			*start;
	t_list			*end;
}					t_enque;

#endif
