##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	source/main.c \
		source/sprites.c \
		source/game_objects.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

DEBUG	=	-g3

#CPPFLAGS= -I./include

CFLAGS	=	-Wall -Wextra $(DEBUG)

LDFLAGS = 	-lm -lcsfml-system -lcsfml-window -lcsfml-graphics 

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
