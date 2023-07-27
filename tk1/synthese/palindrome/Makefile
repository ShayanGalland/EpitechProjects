##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	requirement.c 	\
		sources/main.c	\
		sources/utils.c	\
		sources/string.c \
		sources/palindrome.c \
		sources/check_if_result.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	palindrome

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
