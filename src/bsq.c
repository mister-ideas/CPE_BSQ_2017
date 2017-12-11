/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** bsq.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *buff;
	struct stat s;
	int i = 0;

	if (ac != 2)
		return (84);
	else if (fd == -1)
		return (84);
	stat(av[1], &s);
	if ((buff = malloc(s.st_size + 1)) == NULL)
		return (84);
	while (read(fd, buff + i, 4096) > 0)
	       i += 4096;
	close(fd);
	buff[s.st_size] = '\0';
	my_putstr(buff);
	free(buff);
	return (0);
}
