##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	giantman.c \
		print.c	\
		strings.c \
		uncompress.c \
		uncompress_utils.c \
		utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	giantman

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
