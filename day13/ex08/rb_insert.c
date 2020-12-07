#include "ft_btree_rb.h"

void	rb_make_black(t_rb_node *node)
{
	t_rb_node	*grand;
	t_rb_node	*uncle;
	t_rb_node	*parent;

	parent = node->parent;
	if (!parent)
	{
		node->color = RB_BLACK;
		return ;
	}
	grand = parent->parent;
	parent->color = RB_BLACK;
	if (!grand)
		return ;
	if (grand->left == parent)
		uncle = grand->right;
	else
		uncle = grand->left;
	if (uncle)
		uncle->color = RB_BLACK;
	grand->color = RB_RED;
	rb_make_black(grand);
}

t_rb_node	*rb_balance(t_rb_node *node)
{
	t_rb_node	*parent;
	t_rb_node	*grand;
	t_rb_node	*uncle;

	parent = node->parent;
	grand = parent->parent;
	if (grand->left == parent)
		uncle = grand->right;
	else
		uncle = grand->left;
	if (uncle && uncle->color == RB_RED)
		rb_make_black(node);
	else if (!uncle || uncle->color == RB_BLACK)
	{
		if (parent == grand->left && node != parent->left)
		{
			grand->left = node;
			node->parent = grand;
			node->left = parent;
			parent->parent = node;
			parent->right = NULL;
			parent = node;
			node = parent->left;
		}
		if (parent == grand->right && node != parent->right)
		{
			grand->right = node;
			node->parent = grand;
			node->right = parent;
			parent->parent = node;
			parent->left = NULL;
			parent = node;
			node = parent->right;
		}
		if (parent == grand->left)
		{
			parent->parent = grand->parent;
			grand->parent = parent;
			grand->left = NULL;
			node->right = parent->right;
			parent->right = grand;
		}
		if (parent == grand->right)
		{
			parent->parent = grand->parent;
			grand->parent = parent;
			grand->right = NULL;
			node->left = parent->left;
			parent->left = grand;
		}
		if (parent->parent)
		{
			if ((parent->parent)->right == grand)
				(parent->parent)->right = parent;
			else
				(parent->parent)->left = parent;
		}
		parent->color = RB_BLACK;
		grand->color = RB_RED;
		if (!parent->parent)
			return (parent);
	}
	return (NULL);
}

t_rb_node		*rb_create_node(t_rb_node *parent, void *item)
{
	t_rb_node		*ptr;

	ptr = (t_rb_node*)malloc(sizeof(t_rb_node));
	if (ptr)
	{
		ptr->parent = parent;
		ptr->data = item;
		ptr->right = NULL;
		ptr->left = NULL;
		if (!parent)
			ptr->color = RB_BLACK;
		else
			ptr->color = RB_RED;
	}
	return (ptr);
}

t_rb_node	*rb_find(t_rb_node *root, void *data, int (*cmpf)(void *, void *))
{
	t_rb_node		*tmp;

	if (cmpf(data, root->data) >= 0)
	{
		if (root->right)
			tmp = rb_find(root->right, data, cmpf);
		else
		{
			root->right = rb_create_node(root, data);
			tmp = root->right;
		}
	}
	else
	{
		if (root->left)
			tmp = rb_find(root->left, data, cmpf);
		else
		{
			root->left = rb_create_node(root, data);
			tmp = root->left;
		}
	}
	return (tmp);
}


void	rb_insert(struct s_rb_node **root, void *data, \
	int (*cmpf)(void *, void *))
{
	t_rb_node	*node;
	t_rb_node	*tmp;

	tmp = NULL;
	if (!(*root))
	{
		*root = rb_create_node(NULL, data);
		return ;
	}
	node = rb_find(*root, data, cmpf);
	if ((node->parent)->color == RB_RED)
		tmp = rb_balance(node);
	if (tmp)
		*root = tmp;
}
