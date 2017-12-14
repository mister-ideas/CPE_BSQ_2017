/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** tools.c
*/

#include <stdlib.h>
#include "my.h"
#include "bsq.h"

void file_lines(bsq_t *bsq)
{
	bsq->first_line_size = 0;
	for (int i = 0; bsq->buff[i] != '\n'; i++)
		bsq->first_line_size += 1;
	bsq->lines_nb = 0;
	for (int i = 0; bsq->buff[i]; i++) {
		if (bsq->buff[i] == '\n')
			bsq->lines_nb += 1;
	}
	bsq->lines_nb -= 1;
	bsq->invi_chars = bsq->lines_nb + bsq->first_line_size;
	bsq->col_nb = (bsq->file_size - bsq->invi_chars) / bsq->lines_nb;
}

void check_char(bsq_t *bsq, int x)
{
	int y = 0;
	int j = 0;

	for (y = 0; y < bsq->col_nb; y++) {
		if (bsq->chars[j] == '.')
			bsq->ints[x][y] = 1;
		else if (bsq->chars[j] == 'o')
			bsq->ints[x][y] = 0;
		j++;
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
