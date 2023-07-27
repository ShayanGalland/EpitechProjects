##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	requirement.c 	\
		sources/main.c	\
		sources/string.c \
		sources/utils.c \
		sources/fasta_tools.c \
		sources/my_split.c \
		sources/error.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	FASTAtools

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
