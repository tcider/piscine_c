#include "ft_btree.h"

t_enque		*ft_create_enq(void)
{
	t_enque		*new_enq;

	new_enq = (t_enque*)malloc(sizeof(t_enque));
	new_enq->start = NULL;
	new_enq->end = NULL;
	return (new_enq);
}

void		ft_push_enq(t_enque *enq, t_btree *node, int level)
{
	t_list		*new;
	
	if (!enq)
		enq = ft_create_enq();
	new = (t_list*)malloc(sizeof(t_list));
	new->node = node;
	new->level = level;
	new->next = NULL;
	if (enq->end)
		(enq->end)->next = new;
	enq->end = new;
	if (!enq->start)
		enq->start = new;
}

t_list		*ft_pop_enq(t_enque *enq)
{
	t_list		*tmp_list;

	if (!enq->start)
		return (NULL);
	tmp_list = enq->start;
	if (enq->end == tmp_list)
		enq->end = NULL;
	enq->start = tmp_list->next;
	return (tmp_list);
}
	
void		func(void *item, int curent_level, int is_first_elem)
{
	printf("%s-%d-%d\n", item, curent_level, is_first_elem);
}

void	free_list(t_list *tmp)
{
	tmp->next = NULL;
	tmp->node = NULL;
	tmp->level = 0;
	free(tmp);
}

void btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_enque		*enq;
	t_list		*tmp;
	int			first;
	int			tmp_level;

	first = 1;	
	tmp_level = 0;
	enq = ft_create_enq();
	ft_push_enq(enq, root, tmp_level);
	while ((tmp = ft_pop_enq(enq)))
	{
		if (tmp->level > tmp_level)
		{
			tmp_level = tmp->level;
			first = 1;
		}
		else if (tmp->level)
			first = 0;
		applyf((tmp->node)->item, tmp->level, first);
		if ((tmp->node)->left)
			ft_push_enq(enq, (tmp->node)->left, tmp->level + 1);
		if ((tmp->node)->right)
			ft_push_enq(enq, (tmp->node)->right, tmp->level + 1);
		free_list(tmp);
	}
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

/*
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
	(node->right)->left = left;
	(node->right)->right = right;
*/
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
	((node->left)->left)->right = right;
}

int		main(void)
{
	t_btree		*node;

	node = make_tree("00");
	generate_tree(node);
	btree_apply_by_level(node, func);

	return (0);
}
