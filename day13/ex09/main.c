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

int		f_max(void *s1, void *s2)
{
	if (*((int*)s1) > *((int*)s2))
		return (1);
	else
		return (-1);
}

void	print_tree(t_rb_node *tree)
{
	if (!tree)
		return ;
	print_tree(tree->left);
	if (tree->parent)
		printf ("(%d)", *((int*)((tree->parent)->data)));
	printf("%d(%d)", *((int*)(tree->data)), tree->color);
	if (tree->left)
		printf (" -%d", *((int*)((tree->left)->data)));
	if (tree->right)
		printf (" -%d", *((int*)((tree->right)->data)));
	printf("\n");
	print_tree(tree->right);
}

int		cmpf(void *x, void *y)
{
	return (*((int*)x) - *((int*)y));
}

void	freef(void *p)
{
	void	*a;

	a = p;
	//free(p);
}

int		main(void)
{
	t_rb_node	*root1;
	t_rb_node	**root;

	int			arr[10] = {7, 5, 1, 8, 9, 10, 2, 3, 6, 4};
	//int			arr[6] = {1, 2, 3, 4, 5, 6};
	int			i;

	root1 = NULL;
	root = &root1;
	i = -1;
	while (++i < 10)
		rb_insert(root, (void*)&arr[i], f_max);
	//printf("%d", *((int*)((*root)->data)));
	print_tree(*root);
	//tmp = rb_search(*root, (void*)&arr[5], cmpf);
	//printf("\n%d\n", *((int*)(tmp->data)));
	rb_remove(root, (void*)&arr[1], cmpf, freef);
	printf("\n\n");
	print_tree(*root);
	return (0);
}
