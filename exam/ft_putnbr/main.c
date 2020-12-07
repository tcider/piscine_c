#include <unistd.h>
#include <limits.h>

void ft_putnbr(int num)
{
	int c;


	if (num < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-num);
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	num %= 10;
	c = num + '0';
	write(1, &c, 1);
}

int main()
{
		ft_putnbr(INT_MAX);
	return (0);
}
