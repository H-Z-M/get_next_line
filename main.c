#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

#ifdef L
#include "/home/sss/UTIL/leakdetect.h"
#define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free
#endif

#define SAFE_FREE(p) {free(p); p = NULL;}

enum
{
	SECS_TO_SLEEP = 0,
	NSEC_TO_SLEEP = 100000000
};

struct timespec remaining, request = {SECS_TO_SLEEP, NSEC_TO_SLEEP};
int nanosleep(const struct timespec *request, struct timespec *remain);

int main(int argc, char **argv)
{
#ifdef L
	leak_detect_init();
#endif
#ifdef STDIN
	printf("\x1b[42m\x1b[1mSTDIN\x1b[49m\x1b[0m\n");
	char *l;
	while ((l = get_next_line(0)))
		printf("%s", l);
	leak_detect_check();
	return 0;
#endif
	int j = 0;
	int i = 1;
	int fds[100];
	FILE *fp[100];
	size_t len = 0;
	while (i < argc)
	{
		fds[j] = open(argv[i], O_RDONLY);
		fp[j] = fopen(argv[i], "r");
		i++;
		j++;
	}
	char *line = NULL;
	char *acline = NULL;
	for(i=0; i < argc-1; i++)
	{
		printf("\x1b[46m%s\x1b[49m\n", argv[i+1]);
		while ((acline = get_next_line(fds[i])))
		{
			getline(&line, &len, fp[i]);
			nanosleep(&request, &remaining);
			if (strncmp(line, acline, strlen(acline)))
			{
				printf("diff\n");
				printf("ex => %s", line);
				printf("ac => %s\n", acline);
				printf("%zu\n",strlen(line));
				printf("%zu\n",strlen(acline)+1);
				return EXIT_FAILURE;
			}
			printf("\x1b[7mex => %s\x1b[0m", line);
			printf("ac => %s", acline);
			/* printf("%s", acline); */
			SAFE_FREE(acline);
			SAFE_FREE(line);
		}
		printf("\n");
	}
	SAFE_FREE(acline);
	SAFE_FREE(line);

<<<<<<< HEAD
	/* printf("\x1b[42m\x1b[1mSTDIN\x1b[49m\x1b[0m\n"); */
	/* char *l; */
	/* while ((l = get_next_line(0))) */
	/* 	printf("%s", l); */
<<<<<<< HEAD

=======
>>>>>>> d649aac1d758e9ecefec874cec0667c629af1c86
=======
>>>>>>> 1aee3d3825f5f2e576e529406da45f604cc79a0b
# ifndef __linux__
	system("leaks -q cexe");
# endif
#ifdef L
	leak_detect_check();
#endif
	return EXIT_SUCCESS;
}
