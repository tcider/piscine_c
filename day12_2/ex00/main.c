#include "ft_display_file.h"

void	ft_display_file(int fd)
{
	char	str[BUF];
	int		size;

	while ((size = read(fd, str, BUF)))
		write(1, str, size);
	// в пред версии я нультерминирую буфер надо ли?
}


int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "Error\n", 6);
			return 1;
		}
		ft_display_file(fd);
		if (close(fd) == -1)
		{
			write(1, "Error\n", 6);
			return 1;
		}
	}
	else if (argc == 1)
		write(1, "File name missing.\n", 19);
	else
		write(1, "Too many arguments.\n", 20);
	return 0;
}
