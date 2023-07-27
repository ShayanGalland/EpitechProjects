##
## EPITECH PROJECT, 2021
## Server Makefile
## File description:
## Makefile for server
##

SRC	=	main.c			\
		server.c 		\
		network.c   \
		database.c   \

OBJ	=	$(SRC:.c=.o)

NAME	=	../myteams_server

CFLAGS	=	-g -I../include -L../libs/myteams

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) -l myteams -luuid

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
