#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	if (size <= 1) return ;

	unsigned int	mid;
	int				*left;
	int				*right;	
	int				buf[size];
	unsigned int	li;
	unsigned int	ri;
	unsigned int	i;

	li = 0;
	ri = 0;
	i = -1;
	mid = size / 2;
	left = tab;
	right = left + mid;

	sort_int_tab(left, mid);
	sort_int_tab(right, size - mid);

	while (++i < size)
		buf[i] = 0;
	i = 0;
	while(li < mid && ri < size - mid)
		if (left[li] <= right[ri])
		{
			buf[i] = left[li];
			li++;
			i++;
		}
		else
		{
			buf[i] = right[ri];
			ri++;
			i++;
		}

	while (li < mid)
	{
		buf[i] = left[li];
		li++;
		i++;
	}
	while (ri < size - mid)
	{
		buf[i] = right[ri];
		ri++;
		i++;
	}
	
	i = -1;
	while (++i < size)
		tab[i] = buf[i];
}

int		main(void)
{
	int arr[10] = {8, 9, 9, 0, 1, 3, 5, 0, 1, 0};
	int	i = -1;
	while (++i < 10)
		printf("%d-", arr[i]);
	printf("\n");
	sort_int_tab(arr, 10);
	i = -1;
	while (++i < 10)
		printf("%d-", arr[i]);

	printf("\n");


	return (0);
}
