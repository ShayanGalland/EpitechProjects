##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	source/main.c				\
		source/op.c				\
		source/utils.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

DEBUGFLAG	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L../lib/my -lmy

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) -r $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
