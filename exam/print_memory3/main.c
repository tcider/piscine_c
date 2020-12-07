#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*str;

	str = "0123456789abcdef";
	write(1, &str[c / 16], 1);
	write(1, &str[c % 16], 1);
}

void	print_line(unsigned char *str, size_t start, size_t max)
{
	size_t		j;

	j = start;
	while (j < start + 16)
	{
		if (j < max)
			print_hex(str[j]);
		else
			write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
	j = start;
	while (j < start + 16 && j < max)
	{
		if (str[j] >= ' ' && str[j] <= '~')
			write(1, &str[j], 1);
		else
			write(1, ".", 1);
			j++;
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*ptr;
	size_t	i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_line(ptr, i, size);
		i += 16;
	}
}


int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
