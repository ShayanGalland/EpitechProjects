##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## y
##
SRC	= 	infin_add.c

OBJ     =       $(SRC:.c=.o)

NAME	=	./infin_add

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) infin_add.c -Wall -Wextra
	make -C lib/my/Makefile

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
