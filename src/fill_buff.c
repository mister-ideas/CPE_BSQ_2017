/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** fill_buff.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

int fill_buff(bsq_t *bsq, int fd, char **av)
{
	struct stat s;

	stat(av[1], &s);
	bsq->file_size = s.st_size;
	if ((bsq->buff = malloc(bsq->file_size + 1)) == NULL)
		return (1);
	read(fd, bsq->buff, bsq->file_size);
	close(fd);
	bsq->buff[bsq->file_size] = '\0';
	return (0);
}
