#include <stdio.h>
#include <stdlib.h>

void *ft_print_memory(void *addr, unsigned int size)
{
	char *p;

	p = (char *)addr;
	printf("%c %d", *p, size);
	return p;

}

int main()
{
//	int x = 10;
	int *p;
//	int *y;

//	y = &x;
	p = malloc(sizeof (int)); 
	ft_print_memory(p, 16);

	printf("- %p", p);
	printf("\n\n\n");
//	printf("%d", &x);
}


