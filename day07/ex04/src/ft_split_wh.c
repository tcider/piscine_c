#include <stdlib.h>
#ifndef SPACEC
#define SPACEC(x) (x == '\n' || x == '\t' || x == ' ')
#endif
#include "./../includes/ft_mystdlib.h"

char **ft_split_wh(char *str)
{
	int i, j, l, k;
	char **p;

	i = 0;	
	j = 0;
	l = 0;
	k = -1;
	p = (char**)malloc(sizeof(char*) * (ft_n_words(str) + 1));
	while (str[i])
	{
		if ((!SPACEC(str[i])) && (k == -1))
			k = i;
		else if (SPACEC(str[i]) && (k != -1))
			{
				p[j] = (char*)malloc(sizeof(char) * (i - k + 1));
				l = 0;
				while (l < (i - k))
				{
					p[j][l] = str[k + l];
					l ++;
				}
				p[j][l] = '\0';
				j ++;
				k = -1;
			}
		i ++;
	}
	p[j] = 0;
	return (p);
}
