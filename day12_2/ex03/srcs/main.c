/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:36:34 by tcider            #+#    #+#             */
/*   Updated: 2020/08/05 12:55:52 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	print_er(char *file, char *str)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	write(1, "hexdump: ", 9);
	write(1, file, i);
	write(1, ": ", 2);
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	print_hex_byte(unsigned char byte)
{
	char	*str;

	str = "0123456789abcdef";
	write(1, &(str[byte / 16]), 1);
	write(1, &(str[byte % 16]), 1);
}

void	print_hex(int x)
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
		{
			write(1, "Read file error\n", 16);
			return ;
		}
		buf[a] = '\0';
		a = -1;
		while (buf[++a])
		{
			if (!(count % 16))
			{
				print_hex(count);
				write(1, " ", 1);
			}
			if (!(count % 8))
				write(1, " ", 1);
			print_hex_byte(buf[a]);	
			write(1, " ", 1);
			if (!((count + 1) % 16) || (!buf[a + 1] && a < BUF_SIZE))
			{
				b = 0;
				while (((++b) + count) % 16)
					write(1, "   ", 3);
				if (count % 16 < 8)
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
		}
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
				{
					print_er(argv[i], "No such file or directory");
					continue;
				}
				print_hex_file(fd);
				if (close(fd) == -1)
					print_er(argv[i], "Close file error");
			}
			if (count)
			{
				print_hex(count);
				write(1, "\n", 1);
			}
			else
				print_er(argv[i - 1], "Bad file descriptor");
		}
		else
			write(1, "No -C flag\n", 11);
	}
	else
		write(1, "Arguments wrong\n", 16);
	return (0);
}

