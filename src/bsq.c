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
	bsq_t bsq;
	struct stat s;
	int fd = open(av[1], O_RDONLY);

	if (ac != 2)
		return (84);
	else if (fd == -1)
		return (84);
	stat(av[1], &s);
	if ((bsq.buff = malloc(s.st_size + 1)) == NULL)
		return (84);
	read(fd, bsq.buff, s.st_size);
	close(fd);
	bsq.buff[s.st_size] = '\0';
	my_putstr(bsq.buff);
	free(bsq.buff);
	return (0);
}
