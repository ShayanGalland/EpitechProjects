##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/buildtins.c	\
		sources/commands.c	\
		sources/environs.c	\
		sources/mysh.c		\
		sources/strings.c	\
		sources/utils.c		\
		sources/print.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
