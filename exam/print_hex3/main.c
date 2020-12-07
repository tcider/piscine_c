#include <unistd.h>

void	print_hex(int num)
{
	char c;

	if (num >= 16)
		print_hex(num / 16);
	num %= 16;
	if (num > 9)
		c = num + 'a' - 10;
	else
		c = num + '0';
	write(1, &c, 1);
}


int main()
{
	int num = 100;
	int a = 128;

	while (a)
	{
		if ((a & num) == a)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		a /= 2;
	}
	write(1, "/n", 1);
	print_hex((int)num);
}
