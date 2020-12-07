#include <stdio.h>

int find_solution(int *queens)
{
	int j;
	int i;
	int k;
	int n;

	j = 0;
	i = 0;
	k = 0;
	while (j < 8)
	{
		while ((i < 8) && (k = 0))
		{
			n = 0;
			while ((n < j) && (k = 0))
			{
				if ((i == queens[n]) || (i - j) == (queens[n] - n) || (i + j) == (queens[n] + n))
				{
					k ++;
				}
				n ++;
			}
			if (k == 0)
			{
				queens[j] = i;
				k = 1;
			}
			else
				k = 0;
			i ++;
		}
		if (k == 1)
		{
			j ++;
			i = 0;
			k = 0;
		}
		else
		{
			j --;
			i = queens[j] + 1;
		}
		
	}
	return k;
}


//int ft_eight_queens_puzzle(void)
//{
//	int queens[8];
//	int k;
//
//	k = find_solution(queens);
//	return k;
//}

int main()
{
	int queens[8];
	int i = 0;
	int *str;
	int k;

	while (i <=7)
	{
		queens[i] = 9;
	}
	i = 0;

	str = &queens[0];
	k = find_solution(str);
	while (i <= 7)
	{
		printf("k = %d  --- %d,", k, queens[i]);
		i ++;
	}
}




