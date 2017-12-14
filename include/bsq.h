/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** bsq.h
*/

#ifndef BSQ_H_
#define BSQ_H_

typedef struct bsq {
	char *buff;
	char *chars;
	int **ints;
	int file_size;
	int first_line_size;
	int lines_nb;
	int col_nb;
	int invi_chars;
} bsq_t;

#endif
