##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## minishell 1
##

SRC	=	src/main.c	\
		src/car_directions.c	\
		src/car_speed.c	\
		src/functions.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

CPPFLAGS	=	-I./include/

CFLAGS		=	-Wall -Wextra -pedantic

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	 fclean all

.PHONY:	all clean fclean re
