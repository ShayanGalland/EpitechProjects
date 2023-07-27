##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_split.c	\
		src/array.c	\
		src/block.c	\
		src/open.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	pokemon

CFLAGS	=	-Wall -Wextra -g

LDFLAGS	=	-L./lib/my -lmy	

CPPFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f temp_file.txt
	rm -f *.c~
	rm -f *units_tests
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.tmp
	rm -f vgcore*
	rm -f *~
	make fclean -C lib/my

fclean: clean
	rm -f $(NAME)

re:	fclean all
