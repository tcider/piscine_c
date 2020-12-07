int		ft_power(int n, int pw)
{
	int		x;

	if (!pw)
		return (n);
	if (pw % 2)
		return (n * ft_power(n, pw - 1));
	else
	{
		x = ft_power(n, pw / 2);
		return (x * x);
	}
}

int		check_str(char *str, char *base)
{
}

int		ft_atoi_base(const char *str, int str_base)
{
	char	*base;
	int		i;
	int		size;
	int		num;
	int		sign;
	int		j;

	i = 0;
	size = 0;
	num = 0;
	sign = 1;
	*base = "0123456789abcdef";
	while (str[size])
		size++;
	if (!size || str_base < 2 || str_base > 16)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		j = -1;
		while (base[++j])
			if (str[i] == base[j] || str[i] == base[j] - ('a' - 'A'))
				num += j * ft_power(str_base, --size);





}
