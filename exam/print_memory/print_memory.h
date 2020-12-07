#ifndef PRINT_MEMORY_H
# define PRINT_MEMORY_H

# include <stdio.h>
# include <unistd.h>

void	print_memory(const void *addr, size_t size);
void	print_hex_byte(int num);

#endif
