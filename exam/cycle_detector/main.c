


int		cycle_detector(t_list *begin_list)
{
	t_list	*slow;
	t_list	*fast;

	if (!begin_list)
		return (0);

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);



