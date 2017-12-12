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

void fill_str(bsq_t *bsq)
{
	for (int i = 0; bsq->buff[i]; i++) {
		if (bsq->buff[i] == '\n')
			bsq->str_map[i] = bsq->buff[i + 1];
		else
			bsq->str_map[i] = bsq->buff[i];
	}
	my_putstr(bsq->str_map);
}

void map_stats(bsq_t *bsq)
{
	for (int i = 0; bsq->buff[i]; i++) {
		
	}
}

int main(int ac, char **av)
{
	bsq_t bsq;
	struct stat s;
	int fd = open(av[1], O_RDONLY);
	int i = 0;

	if (ac != 2)
		return (84);
	else if (fd == -1)
		return (84);
	stat(av[1], &s);
	if ((bsq.buff = malloc(s.st_size + 1)) == NULL)
		return (84);
	if ((bsq.str_map = malloc(s.st_size + 1)) == NULL)
		return (84);
	while (read(fd, bsq.buff + i, 4096) > 0)
		i += 4096;
	close(fd);
	bsq.buff[s.st_size] = '\0';
	map_stats(&bsq);
	fill_str(&bsq);
	free(bsq.buff);
	return (0);
}
