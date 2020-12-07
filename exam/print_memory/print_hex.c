#include "print_memory.h"

void	print_hex_byte(int num)
{
	char	*hex;
	
	hex = "0123456789abcdef";
	printf ("%c%c", hex[num / 16], hex[num % 16]);
}
