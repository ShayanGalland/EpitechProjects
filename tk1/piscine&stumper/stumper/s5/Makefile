##
## EPITECH PROJECT, 2022
## y
## File description:
## y
##

SRC     =       main.c

OBJ     =       $(SRC:.c=.o)

NAME    =       rostring

CFLAGS  =       -Wall -Wextra

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all
