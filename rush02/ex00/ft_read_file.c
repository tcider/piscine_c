#include "rush02.h"

t_list	*ft_create_list(char *data, int size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->next = NULL;
	list->data = data;
	list->size = size;
	return (list);
}

void	ft_add_list(t_list **list, char *data, int size)
{
	t_list *new_list;

	if (!*list)
	{
		*list = ft_create_list(data, size);
		return ;
	}
	new_list = *list;
	while (new_list->next)
		new_list = new_list->next;
	new_list->next = ft_create_list(data, size);
}

int		ft_all_size(t_list *list)
{
	int		size;

	size = 0;
	while (list)
	{
		size += list->size;
		list = list->next;
	}
	return (size);
}

char	*ft_concat_buf(t_list *list)
{
	t_list	*tmp_list;
	char	*str;
	int 	i;
	int		j;

	tmp_list = list;
	str = (char*)malloc(sizeof(char) * (ft_all_size(list) + 1));
	j = -1;
	while (list)
	{
		i = -1;
		while ((list->data)[++i])
			str[++j] = (list->data)[i];
		free(list->data);
		tmp_list = list->next;
		free(list);
		list = tmp_list;
	}
	str[++j] = '\0';
	return (str);
}

char	*ft_read_file(int fd)
{
	char	*buf;
	t_list	*list;
	int		size;
	
	list = NULL;
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((size = read(fd, buf, BUF_SIZE)))
	{
		if (size == -1)
			return NULL;
		buf[size] = '\0';
		ft_add_list(&list, buf, size);
		if (size == BUF_SIZE)
			buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	}
	return (ft_concat_buf(list));
}
