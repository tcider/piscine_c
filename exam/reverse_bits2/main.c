#include <unistd.h>
#include <stdlib.h>

void print_bin(unsigned char num)
{
	char	str[9];
	int		i;

	i = 0;
	str[8] = '\0';
	num = (int)num;
	while (++i <= 8)
	{
		str[8 - i] = num % 2 + '0';
		num /= 2;
	}
	write(1, str, 8);
}

void	reverse_bits2(unsigned char octet)
{
	struct	s_bits
	{
		unsigned int	a0:1;
		unsigned int	a1:1;
		unsigned int	a2:1;
		unsigned int	a3:1;
		unsigned int	a4:1;
			unsigned int	a5:1;
		unsigned int	a6:1;
		unsigned int	a7:1;
	};
	union	u_byte
	{
		struct s_bits	arr;
		unsigned char	byte;
	};
	union u_byte	b;
	char			c;

	b.byte = octet;
	c = b.arr.a0 + '0';
	write(1, &c, 1);
	c = b.arr.a1 + '0';
	write(1, &c, 1);
	c = b.arr.a2 + '0';
	write(1, &c, 1);
	c = b.arr.a3 + '0';
	write(1, &c, 1);
	c = b.arr.a4 + '0';
	write(1, &c, 1);
	c = b.arr.a5 + '0';
	write(1, &c, 1);
	c = b.arr.a6 + '0';
	write(1, &c, 1);
	c = b.arr.a7 + '0';
	write(1, &c, 1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	z;
	int				i;

	x = 1;
	i = 7;
	z = 0;
	while (i >= -7)
	{
		y = octet & x;
		x <<= 1;
		if (i > 0)
			y <<= i;
		else
			y >>= -i;
		z = z | y;
		i -= 2;
	}
	return (z);
}

int		main(int argc, char **argv)
{
	unsigned char num;

	if (argc == 2)
	{
		num = (unsigned char)atoi(argv[1]);
		print_bin(num);
		write(1, "\n", 1);
		print_bin(reverse_bits(num));
		write(1, "\n", 1);
		reverse_bits2(num);
	}
	write(1, "\n", 1);
	return (0);
}

