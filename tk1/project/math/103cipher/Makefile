##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

CFLAGS	=	-Wall -Wextra

OFLAGS	=	-lm

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OFLAGS) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
