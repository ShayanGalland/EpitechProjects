##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	main_dante.c	\
		perfect.c	\
		imperfect.c	\
		../commons/cell.c	\
		../lib/set.c \
		../lib/stack.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

CFLAGS	=	-Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
