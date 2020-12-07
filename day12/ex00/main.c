#include "display_file.h"

void	display_file(int fd)
{
	int		ret;

	char	buf[BUF_SIZE + 1];
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		write(1, buf, ret);
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "File not exist.\n", 16);
			return (0);
		}
		display_file(fd);
		if (close(fd) == -1)
		{
			write(1, "Close error.\n", 13);
			return (0);
		}
	}
	else if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	return (0);
}
