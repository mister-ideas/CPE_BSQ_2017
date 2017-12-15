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
