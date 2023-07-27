##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FINALLY
##

SRC	=	disp.c	\
		sort.c 	\
		uniq.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	z

CFLAGS	=	-Wall -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all