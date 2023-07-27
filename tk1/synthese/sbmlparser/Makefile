##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	requirement.c 	\
		sources/main.c	\
		sources/my_split.c 	\
		sources/my_strlen.c	\
		sources/utils.c 	\
		sources/simple_parser.c \
		sources/alphabetic_conv.c \
		sources/different_lines.c 	\
		sources/flags.c	\
		sources/string.c 	\
		sources/search_tag.c \
		sources/tag.c \
		sources/other.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	SBMLparser

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
