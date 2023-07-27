##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	gcc -o

SRC	=	src/main.c	\
		src/fonction.c	\
		src/flags.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	text_count

CFLAGS	=	-Wall -Wextra -g

LDFLAGS	=	-L./lib/my -lmy

CPPFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make fclean -C lib/my

fclean: clean
	rm -f $(NAME)

re:	fclean all clean

.PHONY: re fclean clean all
