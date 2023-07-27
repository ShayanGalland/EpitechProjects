##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	antman.c \
		compress.c \
		compress_utils.c \
		print.c	\
		strings.c \
		utils.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
