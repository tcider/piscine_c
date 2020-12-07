#include "ft_hexdump.h"

void print_hex_byte(unsigned char byte)
{
	char	*str;

	str = "0123456789abcdef";
	write(1, &(str[byte / 16]), 1);
	write(1, &(str[byte % 16]), 1);
}

void print_hex(int x)
{
	char	*str;
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	str = (char*)malloc(8 * sizeof(char) + 1);
	i = 8;
	str[i] = '\0';
	while (x || i)
	{
		i--;
		str[i] = hex[x % 16];
		x = x / 16;
	}
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	print_hex_file(int fd)
{
	unsigned char	buf[BUF_SIZE + 1];
	int		a;
	int		i;
	int		b;

	while ((a = read(fd, buf, BUF_SIZE)))
	{
		if (a == -1)
			perror("Error");
		buf[a] = '\0';
		a = -1;
		while (buf[++a])
		{
			if (!(count % 16))
				print_hex(count);
			if (count % 8 == 0)
				write(1, "  ", 2);
			print_hex_byte(buf[a]);	
			write(1, " ", 1);
			if (!((count + 1) % 16) || (!buf[a + 1] && a < BUF_SIZE))
			{
				b = -1;
				while (((++b) + count) % 16)
					write(1, "   ", 3);
				if ((count) % 16 <= 8)
					write(1, " ", 1);
				i = a - 16 + b;
				write(1, " |", 2);
				while(++i < a)
					if (buf[i] >= ' ' && buf [i] <= '~')
						write(1, &buf[i], 1);
					else
						write(1, ".", 1);
				write(1, "|\n", 2);
			}
			count++;
			// доделать - проверить на маленьком буфере(чтоб файл не разрывался)
			// проверить когда концовка менбеше 8? больше 8 и ровно 16
		}
		// предыдущий код
		/*
		while (buf[++a])
		{
			if (!(count % 16))
			{
				if (count > 1)
				{
					i = a - 17;
					write(1, " |", 2);
					while(++i < a)
						write(1, &buf[i], 1);
					write(1, "|\n", 2);
				}
				print_hex(count);
				write(1, " ", 1);
			}
			if (count % 8 == 0)
				write(1, " ", 1);
			print_hex_byte(buf[a]);
			count++;
			write(1, " ", 1);
		}
		*/
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc > 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C')
		{
			i = 1;
			while (++i < argc)
			{
				if ((fd = open(argv[i], O_RDONLY)) == -1)
					perror("Error");
				print_hex_file(fd);
				if (close(fd) == -1)
					perror("Error");
			}
			//write(1, "\n", 1);
			print_hex(count);
			write(1, "\n", 1);
		}
		else
			write(1, "No -C flag\n", 11);
	}
	else
		write(1, "Arguments wrong\n", 16);
	return (0);
}

