#include <stdlib.h>
// tes
#include <stdio.h>

// не решил услвоие со знаком минус
char	*ft_itoa_base(int value, int base)
{
	char	*str_base;
	int		i;
	int		tmp;
	char	*res;

	str_base = "0123456789ABCDEF";
	tmp = value;
	i = 0;
	while (tmp && ++i)
		tmp = tmp / base;
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while (value)
	{
		tmp = value % base;
		value = value / base;
		res[i - 1] = str_base[tmp];
		i--;
	}
	return (res);
}

int		main(void)
{
	printf("%s\n", ft_itoa_base(123456, 16));

}
