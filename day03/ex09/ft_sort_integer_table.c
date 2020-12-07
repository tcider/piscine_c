#include <stdio.h>

void ft_sort_integer_table(int *tab, int size)
{
	int x;
	int i;

	while (size > 1)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				x = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = x;
			}
			i ++;
		}
		size --;
	}
}

int main()
{
int table[] = {6,7,9,3,1,0,2,8,4,5};
int *tab;
int size;
int i;

size = 10;
tab = &table[0];
ft_sort_integer_table(tab, size);
i = 0;
while(i < size)
{
	printf("%d",tab[i]);
	i ++;

}



}

