##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
