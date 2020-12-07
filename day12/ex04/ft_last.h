#ifndef FT_LAST_H
# define FT_LAST_H

//# define UTMP_FILE "/var/run/utmpx" // for test
# define TIME_BUF 64

# include <utmpx.h>
# include <utmp.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
//# include <errno.h> // обошелся без ерно
# include <time.h>

#endif
