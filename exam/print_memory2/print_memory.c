#include "ft_print_memory.h"

void	print_hex_byte(unsigned char num)
{
	char	*str;

	str = "0123456789abcdef";
	write(1, &str[num / 16], 1);
	write(1, &str[num % 16], 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	size_t	i;
	size_t	j;

	str = (unsigned char*)addr;
	i = 0;
	while (++i <= size)
	{
		print_hex_byte(str[i - 1]);
		if (!(i % 2))
			write(1, " ", 1);
		if (!(i % 16) || i == size)
		{
			if (i == size)
			{
				j = i - 1;
				while ((++j) % 16)
				{
					write(1, "  ", 2);
					if (!(j % 2))
						write(1, " ", 1);
				}
				j = i - i % 16;
			}
			else
				j = i - 17;
			while (++j < i)
				if (str[j] >= ' ' && str[j] <= '~')
					write(1, &str[j], 1);
				else
					write(1, ".", 1);
			write(1, "\n", 1);
		}




	}
}
