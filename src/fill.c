/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** fill.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

int fill_int_map(bsq_t *bsq)
{
	int x = 0;
	int j = 0;

	if ((bsq->ints = malloc(sizeof(int*) * bsq->lines_nb)) == NULL)
		return (1);
	for (int i = 0; i < bsq->lines_nb; i++) {
		if ((bsq->ints[i] = malloc(sizeof(int) * bsq->col_nb)) == NULL)
			return (1);
	}
	for (x = 0; x < bsq->lines_nb; x++) {
		for (int y = 0; y < bsq->col_nb; y++) {
			if (bsq->chars[j] == '.')
				bsq->ints[x][y] = 1;
			else if (bsq->chars[j] == 'o')
				bsq->ints[x][y] = 0;
			else
				return (1);
			j++;
		}
	}
	return (0);
}

int fill_chars_map(bsq_t *bsq)
{
	int j = 0;

	if ((bsq->chars = malloc(bsq->file_size - bsq->invi_chars + 1)) == NULL)
		return (1);
	for (int i = bsq->first_line_size; bsq->buff[i]; i++) {
		if (bsq->buff[i] == '.')
			bsq->chars[j] = '.';
		else if (bsq->buff[i] == 'o')
			bsq->chars[j] = 'o';
		else
			j--;
		j++;
	}
	bsq->chars[j] = '\0';
	return (0);
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
