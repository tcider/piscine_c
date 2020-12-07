#include "ft_last.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void	ft_read_utmp(struct utmpx *s_utmp)
{
	char			timebuf[TIME_BUF];
	struct timeval 	*s_tv;
	
	s_tv = &(s_utmp->ut_tv);
	strftime(timebuf, sizeof timebuf, "%a %b %d %H:%M", localtime(&(s_tv->tv_sec)));
	write(1, s_utmp->ut_user, sizeof(s_utmp->ut_user));
	write(1, "\t", 1);
	write(1, s_utmp->ut_line, sizeof(s_utmp->ut_line));
	write(1, "\t\t\t", 3);
	write(1, timebuf, ft_strlen(timebuf));
	write(1, "\n", 1);
}

int		main(void)
{
	struct utmpx		*s_utmp;
	
	if (utmpxname(_PATH_WTMP))
	{
		write(1, "No file", 7);
		return 1;
	}
	while ((s_utmp = getutxent()))
		ft_read_utmp(s_utmp);
	endutxent();

	/*
	int				fd;
	int				size;			

	s_utmp = (struct utmpx *)malloc(sizeof(struct utmpx));
	if ((fd = open(UTMP_FILE, O_RDONLY)) == -1)
		perror("Error: ");
	size = sizeof(struct utmpx);
	while (size == read(fd, s_utmp, size))
		ft_read_utmp(s_utmp);
	free(s_utmp);
	if (close(fd) == -1)
		perror("Error:");
	*/

	return 0;
}
