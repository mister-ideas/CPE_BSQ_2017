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
	int temp = 0;

	for (int x = 1; x < bsq->lines_nb; x++) {
		for (int y = 1; y < bsq->col_nb; y++)
			find_smallest_int(bsq, temp, x, y);
	}
}

void find_biggest_square(bsq_t *bsq)
{
	bsq->square_size = 0;
	for (int x = 0; x < bsq->lines_nb; x++) {
		for (int y = 0; y < bsq->col_nb; y++)
			square_stats(bsq, x, y);
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

	if ((bsq->final = malloc(bsq->file_size - bsq->first_line)) == NULL)
		return (1);
	for (int i = bsq->first_line + 1; bsq->buff[i]; i++) {
		bsq->final[j] = bsq->buff[i];
		j++;
	}
	bsq->final[j] = '\0';
	for (int x = 0; x < bsq->lines_nb; x++) {
		for (int y = 0; y < bsq->col_nb; y++)
			convert_coordinates(bsq, x, y);
	}
	my_putstr(bsq->final);
	return (0);
}
