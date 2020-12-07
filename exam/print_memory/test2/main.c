#include <unistd.h>

void	print_hex_byte(int num)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	write(1, &hex[num / 16], 1);
	write(1, &hex[num % 16], 1);
}


void	print_memory(const void *addr, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		if (i % 4 == 0)
			write(1, " ", 1);
		if (i % 32 == 0)
		{


		}
		print_hex_byte(p[i]);
		i++;
	}

}

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
