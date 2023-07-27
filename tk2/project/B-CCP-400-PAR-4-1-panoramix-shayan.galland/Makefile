##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	src/main.c 			\
		src/panoramix.c 	\


OBJ	=	$(SRC:.c=.o)

NAME	=	panoramix

CFLAGS	=	-Wall -Wextra -g -lpthread -lrt

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
