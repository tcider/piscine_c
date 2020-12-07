#include "print_memory.h"

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*p;
	size_t			i;
	char			j;

	p = (unsigned char*)addr;
	i = 0;
	while (i <= 16 * size / 16 + 16)
	{		
		if (i >= size)
			printf("  ");
		else
			print_hex_byte(*p);
		i++;
		if (i % 2 == 0)
			printf(" ");
		if (i % 16 == 0)
		{
			p = p - 16;
			j = 0;
			while (++j <= 16 && i - 16 + j <= size)
			{
				p++;
				if (*p >= 32 && *p <= 126)
					printf("%c", *p);
				else
					printf(".");
			}
			printf("\n");
		}
		p++;
	}
}
