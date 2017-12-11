##
## EPITECH PROJECT, 2017
## BSQ
## File description:
## Makefile
##

SRC_DIR=	src

SRC=		$(SRC_DIR)/bsq.c

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -fno-builtin -g

CPPFLAGS =	-I include

LFLAGS=		-L lib/my/ -l my

NAME=		bsq

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src/
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		make clean -C lib/src/
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C lib/src/
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re