#include "ft_cat.h"

void	print_file(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			perror("Error");
		buf[ret] = '\0';
		write(1, buf, ret);
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;

	errno = 0;
	i = 0;
	if (argc == 1)
		print_file(2);
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			perror("Error");
		else
		{
			print_file(fd);
			if (close(fd) == -1)
				perror("Error");
		}
	}
	return (0);
}
