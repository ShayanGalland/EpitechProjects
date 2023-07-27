##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	main_dante_b.c	\
		../commons/cell.c	\
		../lib/set.c \
		../lib/stack.c \
		resolve.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
