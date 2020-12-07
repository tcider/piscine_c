#include <unistd.h>
#include <stdio.h>

void	print_hex_b_end(int	num)
{
	char	*hex;
	int		tmp;
	char	i;
	char	j;

	hex = "0123456789abcdef";
	tmp = num;
	i = 1;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		i++;
	}
	j = i;
	while (++j <= 8)
		printf("0");
	printf("%c", hex[tmp]);
	while (--i >= 1)
	{
		tmp = num;
		j = i;
		while (--j > 0)
			tmp = tmp / 16;
		printf("%c", hex[tmp % 16]);
	}
}

void	print_hex_l_end(int num)
{
	char	*hex;
	char	i;
	int		tmp;

	hex = "0123456789abcdef";
	i = 1;
	tmp = num;
	while (tmp >= 256)
	{
		tmp = tmp / 16;
		i++;
	}
	if (i > 1 && i % 2 == 0)
	{
		printf("%c0", hex[num % 16]);
		num = num / 16;
		i++;
	}
	while (num / 16 >= 256)
	{
		printf("%c%c", hex[(num / 16) % 16], hex[num % 16]);
		num = num / 256;
	}
	printf ("%c%c", hex[num / 16], hex[num % 16]);
	while (i < 7)
	{
		printf("0");
		i++;
	}
}

int	main(void)
{
	print_hex_b_end(12345678);
	printf("\n");
	print_hex_l_end(12345678);
	printf("\n");
	return(0);
}
