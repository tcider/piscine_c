#include "ft_btree.h"
#include <stdio.h> //for test

int		ft_max(int x, int y)
{
	if (x >y)
		return (x);
	else
		return (y);
}

int		btree_level_count(t_btree *root)
{
	if (root)
		return (ft_max(btree_level_count(root->left), btree_level_count(root->right)) + 1);
	return (0);
}

t_btree		*make_tree(void *p)
{
	t_btree		*node;

	node = (t_btree*)malloc(sizeof(t_btree));
	node->left = NULL;
	node->right = NULL;
	node->item = p;
	return (node);
}

void		generate_tree(t_btree *node)
{
	t_btree 	*left;
	t_btree		*right;

	left = make_tree("11");
	right = make_tree("12");
	node->left = left;
	node->right = right;
	left = make_tree("21");
	right = make_tree("22");
	(node->left)->left = left;
	(node->left)->right = right;
	left = make_tree("23");
	right = make_tree("24");
	((node->left)->left)->left = left;
	(((node->left)->left)->left)->right = right;
}

int		main(void)
{
	t_btree		*node;

	node = make_tree("00");
	generate_tree(node);

	printf("%d\n", btree_level_count(node));
	return (0);
}
