#include "ft_btree_rb.h"

t_rb_node	*rb_search(t_rb_node *node, void *data, int (*cmpf)(void *, void *))
{
	t_rb_node	*tmp;

	tmp = NULL;
	if (!cmpf(node->data, data))
		return (node);
	if (node->left)
		tmp = rb_search(node->left, data, cmpf);
	if (node->right)
		tmp = rb_search(node->right, data, cmpf);
	return (tmp);
}

t_rb_node	*rb_remove_node(t_rb_node *node)
{
	t_rb_node	*tmp;

	tmp = node;
	if (!node->left && !node->right && node->parent && node == (node->parent)->right)
		(node->parent)->right = NULL;
	if (!node->left && !node->right && node->parent && node == (node->parent)->left)
		(node->parent)->left = NULL;
	if (node->right && !node->left)
		tmp = node->right;
	if (!node->right && node->left)
		tmp = node->right;
	tmp->parent = node->parent;
	if (node->parent && node == (node->parent)->right)
		(node->parent)->right = tmp;
	if (node->parent && node == (node->parent)->left)
		(node->parent)->left = tmp;
	if (node->right && node->left)
	{
		node = node->right;
		while(node->left)
			node = node->left;
		tmp->data = node->data;
		tmp = rb_remove_node(node);
	}
	return (tmp);
}

void	rb_color(t_rb_node *node)
{
	t_rb_node	*bro;
	
	bro = NULL;
	if ((node->parent)->left == node)
		bro = (node->parent)->right;
	if ((node->parent)->right == node)
		bro = (node->parent)->left;
	// не доделал	



}

void	rb_remove(struct s_rb_node **root, void *data, \
	int (*cmpf)(void *, void *), void (*freef)(void *))
{
	t_rb_node	*node;

	if (!(*root))
		return ;
	if (!(node = rb_search(*root, data, cmpf)))
		return ;
	freef(node->data);
	node = rb_remove_node(node);
	if (node->parent && node->color == RB_BLACK)
	{
		if (node->left)
			rb_color(node->left);
		if (node->right)
			rb_color(node->right);
	}
	if (!node->parent && !(node->left)->parent && !node->right)
		*root = node->left;
	if (!node->parent && !(node->right)->parent && !node->left)
		*root = node->right;
	(*root)->color = RB_BLACK;
	free(node);
	node = NULL;
}

