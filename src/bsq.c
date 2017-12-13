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

void file_lines(bsq_t *bsq)
{
	char temp[12];
	int visible_chars = 0;
	int i;

	bsq->lines_nb = 0;
	bsq->columns_nb = 0;
	for (i = 0; bsq->buff[i] != '\n'; i++)
		temp[i] = bsq->buff[i];
	temp[i + 1] = '\0';
	bsq->lines_nb = my_getnbr(temp);
	visible_chars = bsq->lines_nb + my_strlen(temp);
	bsq->columns_nb = ((bsq->file_size - visible_chars) / bsq->lines_nb);
	printf("%d\n", bsq->columns_nb);
}

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

int main(int ac, char **av)
{
	bsq_t bsq;
	int fd = open(av[1], O_RDONLY);

	if (ac != 2)
		return (84);
	else if (fd == -1)
		return (84);
	if (fill_buff(&bsq, fd, av) == 1)
		return (84);
	file_lines(&bsq);
	free(bsq.buff);
	return (0);
}
