#include <unistd.h>

int		ft_str_num(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!(str[i] > '0' && str[i] < '9'))
			return (-1);
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (i)
		return (num);
	else
		return (-1);
}

int		main(int argc, char **argv)
{
	int		num;

	if (argc != 2 || ft_str_num(argv[1]) == -1)
	{
		write(1, "0\n", 2);
		return(1);
	}
	num = ft_str_num(argv[1]);
}
// не доделал
