##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## y
##

SRC 	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
