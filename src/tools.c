/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** tools.c
*/

#include <stdlib.h>
#include "my.h"
#include "bsq.h"

void find_smallest_int(bsq_t *bsq, int temp, int x, int y)
{
	if (bsq->ints[x][y] != 0) {
		temp = bsq->ints[x - 1][y];
		if (temp > bsq->ints[x][y - 1])
			temp = bsq->ints[x][y - 1];
		if (temp > bsq->ints[x - 1][y - 1])
			temp = bsq->ints[x - 1][y - 1];
		bsq->ints[x][y] += temp;
	}
}

void convert_coordinates(bsq_t *bsq, int x, int y)
{
	if (bsq->ints[x][y] == -1)
		bsq->final[x * bsq->col_nb + y + x] = 'x';
}

void file_stats(bsq_t *bsq)
{
	bsq->first_line = 0;
	for (int i = 0; bsq->buff[i] != '\n'; i++)
		bsq->first_line += 1;
	bsq->lines_nb = 0;
	for (int i = 0; bsq->buff[i]; i++) {
		if (bsq->buff[i] == '\n')
			bsq->lines_nb += 1;
	}
	bsq->lines_nb -= 1;
	bsq->invi_chars = bsq->lines_nb + bsq->first_line;
	bsq->col_nb = (bsq->file_size - bsq->invi_chars) / bsq->lines_nb;
}

void square_stats(bsq_t *bsq, int x, int y)
{
	if (bsq->square_size < bsq->ints[x][y]) {
		bsq->x = x;
		bsq->y = y;
		bsq->square_size = bsq->ints[x][y];
	}
}

void free_all(bsq_t *bsq)
{
	for (int i = 0; i < bsq->lines_nb; i++)
		free(bsq->ints[i]);
	free(bsq->final);
	free(bsq->ints);
	free(bsq->chars);
	free(bsq->buff);
	free(bsq);
}
