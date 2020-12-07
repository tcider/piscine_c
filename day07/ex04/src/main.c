#include <stdio.h>
#include "./../includes/ft_split_wh.h"

int main()
{
	char string[] = "   This is my \n sentence.  ";
	char **str;
	int i = 0;
	int j;

	str = ft_split_wh(string);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			printf("%c", str[i][j]);
			j ++;
		}
		printf("\n");
		i ++;
	}
}
