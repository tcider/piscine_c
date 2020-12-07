#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H

# include <stdlib.h>
# include <stdio.h> // for test

enum				e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct		s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*right;
	struct s_rb_node	*left;
	void				*data;
	enum e_rb_color		color;
}					t_rb_node;

t_rb_node	*rb_search(t_rb_node *node, void *data, int (*cmpf)(void *, void *));//for tes

void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), \
	void (*freef)(void *));

#endif
