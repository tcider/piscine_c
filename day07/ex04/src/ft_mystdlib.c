#include <unistd.h>
#ifndef SPACEC
#define SPACEC(x) (x == '\n' || x == '\t' || x == ' ')
#endif

int ft_n_words(char *str)
{
	int i;
	int counter;
	char spaceflag;

	counter = 0;
	i = 0;
	spaceflag = 0;
	while (str[i])
	{
		if (!SPACEC(str[i]))
		{
			if (spaceflag == 0)
				counter ++;
			spaceflag = 1;
		}
		else
			spaceflag = 0;
		i ++;
	}
	return (counter);
}

void ft_putchar (char c)
{
	write(1, &c, 1);
}

