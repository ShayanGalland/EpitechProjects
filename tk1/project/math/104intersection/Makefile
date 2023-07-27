##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/main.c	\
		sources/sphere.c	\
		sources/cone.c	\
		sources/cylindre.c	\
		sources/help.c	\
		sources/result.c	\
		sources/result_two.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	104intersection

CFLAGS	=	-Wall -Wextra

OFLAGS	=	-lm

INCLUDE	=	-I./

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(INCULDE) $(OFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
