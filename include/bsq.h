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
	char *final;
	int file_size;
	int first_line;
	int lines_nb;
	int col_nb;
	int invi_chars;
	int x;
	int y;
	int square_size;
} bsq_t;

int biggest_square(bsq_t *bsq, int fd, char **av);
int fill_int_map(bsq_t *bsq);
int fill_chars_map(bsq_t *bsq);
int fill_buff(bsq_t *bsq, int fd, char **av);
int print_final_map(bsq_t *bsq);

void file_lines(bsq_t *bsq);
void check_char(bsq_t *bsq, int x);
void free_all(bsq_t *bsq);
void convert_int_map(bsq_t *bsq);
void find_biggest_square(bsq_t *bsq);

#endif
