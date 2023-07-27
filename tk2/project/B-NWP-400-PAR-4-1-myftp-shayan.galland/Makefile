##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	src/main.c 			\
		src/commands.c		\
		src/commands_handling.c \
		src/commands_show.c \
		src/commands_action.c \
		src/utils.c \
		src/server_init.c \
		src/create_server.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS	=	-Wall -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
