/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** algo.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

void convert_int_map(bsq_t *bsq)
{
	int temp;

	for (int x = 1; x < bsq->lines_nb; x++) {
		for (int y = 1; y < bsq->col_nb; y++) {
			if (bsq->ints[x][y] != 0) {
				temp = bsq->ints[x - 1][y];
				if (temp > bsq->ints[x][y - 1])
					temp = bsq->ints[x][y - 1];
				if (temp > bsq->ints[x - 1][y - 1])
					temp = bsq->ints[x - 1][y - 1];
				bsq->ints[x][y] += temp;
			}
		}
	}
}

void find_biggest_square(bsq_t *bsq)
{
	bsq->square_size = 0;
	for (int x = 1; x < bsq->lines_nb; x++) {
		for (int y = 1; y < bsq->col_nb; y++) {
			if (bsq->square_size < bsq->ints[x][y]) {
				bsq->x = x;
				bsq->y = y;
				bsq->square_size = bsq->ints[x][y];
			}
		}
	}
	for (int x = bsq->x; x > bsq->x - bsq->square_size ; x--) {
		for (int y = bsq->y; y > bsq->y - bsq->square_size; y--) {
			bsq->ints[x][y] = -1;
		}
	}
}

int print_final_map(bsq_t *bsq)
{
	int j = 0;

	if ((bsq->final = malloc(bsq->file_size - 3)) == NULL)
		return (1);
	for (int i = 4; bsq->buff[i]; i++) {
		bsq->final[j] = bsq->buff[i];
		j++;
	}
	bsq->final[j] = '\0';
	for (int x = 1; x < bsq->lines_nb; x++) {
		for (int y = 1; y < bsq->col_nb; y++) {
			if (bsq->ints[x][y] == -1)
				bsq->final[x * bsq->col_nb + y + x] = 'x';
		}
	}
	my_putstr(bsq->final);
	return (0);
}
