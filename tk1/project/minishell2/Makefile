##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/buildtins.c				\
		sources/commands.c				\
		sources/environs.c				\
		sources/mysh.c					\
		sources/strings.c				\
		sources/utils.c					\
		sources/print.c					\
		sources/buildtin_unsetenv.c		\
		sources/buildtin_setenv.c		\
		sources/utils_str.c 			\
		sources/colon.c 				\
		sources/pipe.c 					\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all