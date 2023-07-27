##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FINALLY
##

NAME 	=	libstring.a

SRC 	=	test_main.c	\
			append.c 	\
			assign.c 	\
			at.c		\
			clear.c 	\

AR	=	ar rc

OBJ		=	$(SRC:.c=.o)

CFLAGS=		-std=gnu17 -Wall -Wextra

CPPFLAGS=	-I./

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) $(OBJ)

debug	:	CFLAGS += -g
debug	:	re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
