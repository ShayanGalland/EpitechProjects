##
## EPITECH PROJECT, 2021
## client Makefile
## File description:
## Makefile for client
##

SRC	=	main.c		\
		client.c 	\
		network.c   \

OBJ	=	$(SRC:.c=.o)

NAME	=	../myteams_cli

CFLAGS	=	-g -I../include -L../libs/myteams 

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) -l myteams

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
