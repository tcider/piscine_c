int	ft_str_cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str1[i] && !str2[i])
		return (0);
	else if (str1[i] && str2[i])
		return (str1[i] - str2[i]);
	else if (str1[i] && !str2[i])
		return (str1[i]);
	else
		return (-str2[i]);
}

