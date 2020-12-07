#include "ft_btree_rb.h"

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
	return (0);
}
