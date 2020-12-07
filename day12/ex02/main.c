#include "ft_tail.h"

int		get_st(char *str)
{
	int		i;
	int		st;
	int		sign;

	st = 0;
	sign = -1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '+')
			sign = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			st = st * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	return (st * sign);
}

void	print_file_st(int fd, int st)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		whence;

	if (st <= 0)
		whence = SEEK_END;
	else
	{
		whence = SEEK_SET;
		st--;
	}
	if (lseek(fd, st, whence) == -1)
		perror("Error");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			perror("Error");
		buf[ret] = '\0';
		write(1, buf, ret);
	}
}

void	print_files_st(char **argv, int n, int st)
{
	int		fd;
	int		i;
	int		j;

	errno = 0;
	i = -1;
	while (++i < n)
	{
		if ((fd = open(*argv, O_RDONLY)) == -1)
			perror("Error");
		else
		{
			if (n > 1)
			{
				j = 0;
				while ((*argv)[j])
					j++;
				if (i > 0)
					write(1, "\n", 1);
				write(1, "==> ", 4);
				write(1, *argv, j);
				write(1, " <==\n", 5);
			}
			print_file_st(fd, st);
			if (close(fd) == -1)
				perror("Error");
		}
		argv++;
	}
}

int		main(int argc, char **argv)
{
	int			i;
	int			st;

	if (argc > 2)
	{
		st = 0;
		if (argv[1][0] != '-' || argv[1][1] != 'c')
		{
			write (1, "No -c flag\n", 11);
			return (0);
		}
		if (argv[1][2])
			st = get_st(&argv[1][2]);
		else
			st = get_st(argv[2]);
		/*
		if (st == 0)
		{
			write (1, "Illegal offset\n", 15);
			return (0);
		}
		*/
		i = 3;
		if (argv[1][2])
			i--;
		print_files_st(&argv[i], argc - i, st);
	}
	else
		write(1, "No arguments\n", 13);
	return (0);
}
