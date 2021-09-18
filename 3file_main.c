#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <time.h>

enum
{
	SECS_TO_SLEEP = 0,
	NSEC_TO_SLEEP = 100000000
};
struct timespec remaining, request = {SECS_TO_SLEEP, NSEC_TO_SLEEP};
int nanosleep(const struct timespec *request, struct timespec *remain);

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (printf("invalid arg\n"));
	int a = 1;
	char *ln;
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	int fd3 = open(argv[3], O_RDONLY);
	printf("\x1b[43m[fd:%d] [%s]\x1b[49m\n",   fd1, argv[1]);
	printf("\x1b[45m[fd:%d] [%s]\x1b[49m\n",   fd2, argv[2]);
	printf("\x1b[46m[fd:%d] [%s]\x1b[49m\n\n", fd3, argv[3]);
	int idx = 0;
	int x = 1, y = 1, z = 1;
	while (x || y || z)
	{
		if (idx % 3 == 0 && x)
		{
			nanosleep(&request, &remaining);
			ln = get_next_line(fd1);
			if (ln)
				printf("\x1b[43m[fd:%d] [line:%3d]\x1b[49m %s", fd1, a, ln);
			else
			{
				printf("\x1b[44mEOF : fd %d %s\x1b[49m\n", fd1, ln);
				x = 0;
			}
			free(ln);
		}
		else if(idx % 3 == 1 && y)
		{
			nanosleep(&request, &remaining);
			ln = get_next_line(fd2);
			if (ln)
				printf("\x1b[45m[fd:%d] [line:%3d]\x1b[49m %s", fd2, a, ln);
			else
			{
				printf("\x1b[44mEOF : fd %d %s\x1b[49m\n", fd2, ln);
				y = 0;
			}
			free(ln);
		}
		else if (idx % 3 == 2 && z)
		{
			nanosleep(&request, &remaining);
			ln = get_next_line(fd3);
			if (ln)
				printf("\x1b[46m[fd:%d] [line:%3d]\x1b[49m %s", fd3, a, ln);
			else
			{
				printf("\x1b[44mEOF : fd %d %s\x1b[49m\n", fd3, ln);
				z = 0;
			}
			free(ln);
		}
		idx++;
		a++;
	}
	close(fd1);
	close(fd2);
	close(fd3);

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	x = 1, y = 1, z = 1;
	while (x || y || z)
	{
		if (idx % 3 == 2 && x)
		{
			nanosleep(&request, &remaining);
			ln = get_next_line(fd1);
			if (ln)
				printf("\x1b[43m[fd:%d] [line:%3d]\x1b[49m %s", fd1, a, ln);
			else
			{
				printf("\x1b[44mEOF : fd %d %s\x1b[49m\n", fd1, ln);
				x = 0;
			}
			free(ln);
		}
		else if(idx % 3 == 1 && y)
		{
			nanosleep(&request, &remaining);
			ln = get_next_line(fd2);
			if (ln)
				printf("\x1b[45m[fd:%d] [line:%3d]\x1b[49m %s", fd2, a, ln);
			else
			{
				printf("\x1b[44mEOF : fd %d %s\x1b[49m\n", fd2, ln);
				y = 0;
			}
			free(ln);
		}
		else if (idx % 3 == 0 && z)
		{
			nanosleep(&request, &remaining);
			ln = get_next_line(fd3);
			if (ln)
				printf("\x1b[46m[fd:%d] [line:%3d]\x1b[49m %s", fd3, a, ln);
			else
			{
				printf("\x1b[44mEOF : fd %d %s\x1b[49m\n", fd3, ln);
				z = 0;
			}
			free(ln);
		}
		idx++;
		a++;
	}
	close(fd1);
	close(fd2);
	close(fd3);

# ifndef __linux__
	system("leaks -q cexe");
# endif
	return 0;
}
