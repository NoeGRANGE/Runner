##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## oui
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

INC = -I./includes

CFLAGS	=	-Wall -Wextra -g3 $(INC)

CFLAG	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

name: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CFLAG) -lm $(INC)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
	rm -f $(OBJ)
	rm -f *~

all:	name
