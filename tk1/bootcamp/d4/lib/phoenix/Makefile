##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##
SRC	=	is_prime_number.c	\
		my_strcpy.c		\
		my_strncmp.c		\
		my_strstr.c		\
		reverse_string.c	\
		show_number.c		\
		show_string.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libphoenix.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar -rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
