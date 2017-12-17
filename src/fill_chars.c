/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** fill_chars.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

int fill_chars_map(bsq_t *bsq)
{
	int j = 0;

	if ((bsq->chars = malloc(bsq->file_size - bsq->invi_chars + 1)) == NULL)
		return (1);
	for (int i = bsq->first_line; bsq->buff[i]; i++) {
		if (bsq->buff[i] == '.')
			bsq->chars[j] = '.';
		else if (bsq->buff[i] == 'o')
			bsq->chars[j] = 'o';
		else
			j--;
		j++;
	}
	if (j == 1)
		bsq->col_nb = 1;
	bsq->chars[j] = '\0';
	return (0);
}
