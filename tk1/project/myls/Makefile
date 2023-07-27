##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

SRC	=	sources/ls_a.c		\
		sources/ls_br.c 	\
		sources/ls_d.c 		\
		sources/ls_flags.c  \
		sources/ls_l.c 		\
		sources/ls_r.c 		\
		sources/ls.c 		\
		sources/main.c 		\
		sources/write.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
