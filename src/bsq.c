/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** bsq.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

int biggest_square(bsq_t *bsq, int fd, char **av)
{
	if (fill_buff(bsq, fd, av) == 1)
		return (1);
	file_lines(bsq);
	if (fill_chars_map(bsq) == 1)
		return (1);
	if (fill_int_map(bsq) == 1)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	bsq_t *bsq = malloc(sizeof(bsq_t));
	int fd = open(av[1], O_RDONLY);

	if (ac != 2)
		return (84);
	else if (fd == -1)
		return (84);
	if (biggest_square(bsq, fd, av) == 1)
		return (84);
	free_all(bsq);
	return (0);
}
