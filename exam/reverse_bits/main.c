#include <stdio.h>

void	print_byte(unsigned char num);

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	char			i;

	a = 0;
	b = 1;
	i = 7;
	while (i >= -7)
	{
		c = octet & b;
		if (i > 0)
			c <<=  i;
		else
			c >>= -i;
		a |= c;
		b <<= 1;
		i -= 2;
	}
	return (a);
}

void	print_byte(unsigned char num)
{
	char	arr[8];
	int		i;

	i = -1;
	while (++i <= 7)
		arr[i] = '0';
	i = 7;
	while (num >= 2)
	{
		arr[i] = '0' + num % 2;
		num = num / 2;
		i--;
	}
	arr[i] = '0' + num;
	i = -1;
	while (++i <= 7)
		printf("%c", arr[i]);
	printf("\n");
}

void	print_byte_union(unsigned char num)
{
	struct	s_byte
	{
		unsigned	a0:1;
		unsigned	a1:1;
		unsigned	a2:1;
		unsigned	a3:1;
		unsigned	a4:1;
		unsigned	a5:1;
		unsigned	a6:1;
		unsigned	a7:1;
	};
	typedef union	u_byte
	{
		unsigned char	value;
		struct s_byte	bytes;
	}				t_byte;
	/*
	typedef union	u_byte
	{
		unsigned char	value;
		unsigned		arr[7]:1;
	}				t_byte;
	*/
	t_byte	byte;

	byte.value = num;
	printf("%d", byte.bytes.a0);
	printf("%d", byte.bytes.a1);
	printf("%d", byte.bytes.a2);
	printf("%d", byte.bytes.a3);
	printf("%d", byte.bytes.a4);
	printf("%d", byte.bytes.a5);
	printf("%d", byte.bytes.a6);
	printf("%d", byte.bytes.a7);
}


int		main(void)
{
	unsigned char	num;

	num = 1;
	print_byte(num);
	printf("\n");
	print_byte(reverse_bits(num));

	return (0);
}

