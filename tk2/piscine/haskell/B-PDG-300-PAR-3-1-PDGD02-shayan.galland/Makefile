##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	DoOp.hs	\

OBJ	=	$(SRC:.hs=.o)

NAME	=	doop

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		ghc -o $(NAME) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
